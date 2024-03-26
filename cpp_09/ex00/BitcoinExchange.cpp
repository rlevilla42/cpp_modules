#include "BitcoinExchange.hpp"

/************** constructor *************/

BitcoinExchange::BitcoinExchange(void) {return;};

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
    if (this != &src) {
        this->_data = src._data;
        this->_mapInput = src._mapInput;
    }
    return;
};

BitcoinExchange::~BitcoinExchange(void) {return;};

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {return(*this);}

/************** function *************/

std::map<std::string, float>    BitcoinExchange::getData(void) {return this->_data;};

/********   PARSE DATA.CSV SOURCE FILE  ********/

void                            BitcoinExchange::fileDataStruct(std::string line) {
    std::cout << line << std::endl;
    this->_dataKeyValue = line.substr(0, 10);
    std::cout << this->_dataKeyValue << std::endl;
    std::string tempValue = line.substr(11, line.size() - 1);
    std::cout << tempValue << std::endl;
    const char *temp_cstr = tempValue.c_str();
    this->_dataValue = static_cast<float>(std::strtod(temp_cstr, NULL));
    //std::cout << std::fixed << std::setprecision(2) << "_dataKeyValue = " << this->_dataKeyValue << " | "
    //<< "_dataValue = " << this->_dataValue << std::endl;
    return ;
};

void                            BitcoinExchange::parseFileToData(const char *file_csv) {
    std::ifstream file(file_csv);
    std::string line;
    if (file.is_open())
    {
        std::getline(file, line); // i call it one before loop because i want to start parse since line 2 and not one
        while (std::getline(file, line)) {
            fileDataStruct(line);
            this->_data[this->_dataKeyValue] = this->_dataValue;
        }
        std::map<std::string, float>::iterator it;
        std::map<std::string, float>::iterator ite = this->_data.end();
        for (it = this->_data.begin(); it != ite; it++) {
            std::cout<< std::fixed << std::setprecision(2)
            << "_data[" << it->first << "] = " << it->second << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open " << file_csv << std::endl;
    }
    return ;
}

/********   PARSE THE INPUT FILE  ********/

void                            BitcoinExchange::fileMapInput(std::string line) {
    int i = 0;
    while (i < line.size() && line[i] != 32) { // looking for date parsing to key value of map
        i++;
    }
    this->_inputKeyValue = line.substr(0, i);
    while (i < line.size() && line[i] != '|') { // start parsing the number of btc
        i++;
    }
    i++;
    std::string tempValue = line.substr(i, line.size() - 1);
    const char *temp_cstr = tempValue.c_str();
    this->_inputValue = static_cast<float>(std::strtod(temp_cstr, NULL));
    //if (this->_inputValue <= 0.0) {std::cout << "Error: BTC number should be positive" << std::endl;return;}
    //if (this->_inputValue > 2147483647.0) {std::cout << "Error: BTC number is too large" << std::endl;return;}
    return ;
};

void                            BitcoinExchange::parseFileToRead(const char *file_input) {
    std::ifstream file(file_input);
    std::string line;
    if (file.is_open()) {
        std::getline(file, line); // i call it one before loop because i want to start parse since line 2 and not one
        while (std::getline(file, line)) {
            if (dateFormat(line) == 0) {
                fileMapInput(line);
                this->_mapInput[this->_inputKeyValue] = this->_inputValue;
                outputResult();
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open " << file_input << std::endl;
    }
};

int dateFormat(std::string line) {
    if (checkValue(line) == 1) {
        return (1);
    }
    /*int flag_pipe_exist = 0;
    for (int z = 0; z < line.size(); z++) {
        if (line[z] == '|') {
            flag_pipe_exist++;
        }
    }
    if (flag_pipe_exist != 1) {
        std::cout << "Error: Wrong input value" << std::endl;
        return (1);
    }*/
    double year, month, day;
    int i = 0;
    int k = 0;
    while (i < line.size() && line[i] != '-') {i++;}
    year = strtod(line.substr(0, i).c_str(), NULL);
    int biSexYear = static_cast<int>(year);
    i++;
    int j = i;
    while (i < line.size() && line[i] != '-') {i++;}
    month = strtod(line.substr(j, i).c_str(), NULL);
    i++;
    j = i;
   while (i < line.size() && line[i] != '-') {i++;}
    day = strtod(line.substr(j, i).c_str(), NULL);
    if (year < 2009.0) {
        std::cout << "Error: BTC didn't exist yet => " << line << std::endl;
        return (1);
    } else if (month > 12.0 || month < 1.0) {
        std::cout << "Error format date: We have 12 months in the calendrary bro => " << line << std::endl;
    } else if (isLeapYear(biSexYear) && month == 2.0 && day > 29.0) {
        std::cout << "Error: February cannot have more than 29 days in a bisex year => " << line << std::endl;
        return (1);
    } else if (isLeapYear(biSexYear) == false && month == 2.0 && day > 28.0) {
        std::cout << "Error: February cannot have more than 28 days => " << line << std::endl;
        return (1);
    } else if ((month == 1.0 || month == 3.0 || month == 5.0 || month == 7.0 || month == 8.0 || month == 10.0 || month == 12.0) && day > 31.0) {
        std::cout << "Error: Month cannot have more than 31 days => " << line << std::endl;
        return (1);
    } else if (month == 4.0 || month == 6.0 || month == 9.0 || month == 11.0 && day > 30.0) {
        std::cout << "Error: These Month cannot have more than 30 days => " << line << std::endl;
        return (1);
    }
    return (0);
};

bool isLeapYear(int year) {
    // Leap years are divisible by 4
    if (year % 4 == 0) {
        // Unless they are also divisible by 100 but not divisible by 400
        if (year % 100 == 0 && year % 400 != 0) {
            return false;
        }
        return true;
    }
    return false;
};

void    BitcoinExchange::outputResult(void) {
    std::map<std::string, float>::iterator it_data;
    std::map<std::string, float>::iterator ite_data = this->_data.end();
    std::map<std::string, float>::iterator it_data_up = _data.upper_bound(this->_inputKeyValue);
    if (it_data_up == ite_data) {}
};

void    BitcoinExchange::execute(const char *file_input) {
    //parseFileToData("data.csv");
    parseFileToRead(file_input);
    //checkValue("2012-01-11 | 0");
    return ;
};

int    checkValue(std::string line) {
    int flag_pipe_exist = 0;
    for (int z = 0; z < line.size(); z++) {
        if (line[z] == '|') {
            flag_pipe_exist++;
        }
    }
    if (flag_pipe_exist != 1) {
        std::cout << "Error: Wrong input value" << std::endl;
        return (1);
    }
    int i = 0;
    while (line[i] != '|') {i++;}
    i++;
    float   temp = static_cast<float>(strtod(line.substr(i, line.size() - 1).c_str(), NULL));
    if (temp <= 0.0) {
        std::cout << "Error: BTC number should be positive" << std::endl;
        return (1);
    } else if (temp > 2147483647.0) {
        std::cout << "Error: BTC number is too large" << std::endl;
        return (1);
    }
    //std::cout << "float temp = " << temp << std::endl;
    return (0);
};
//std::ostream &operator<<(std::ostream &o, BitcoinExchange const &i) {o << i.get();return o;};