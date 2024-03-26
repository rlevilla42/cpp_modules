#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
//#include <exception>

class BitcoinExchange {
public:
    BitcoinExchange(void);
    BitcoinExchange(BitcoinExchange const &src);
    ~BitcoinExchange(void);

    std::map<std::string, float>    getData(void);
    void                            parseFileToData(const char *file_csv);
    void                            fileMapKeyValue();
    void                            fileMapValue();
    void                            fileDataStruct(std::string line);
    void                            parseFileToRead(const char *file_input);
    void                            fileMapInput(std::string line);
    //int                           checkFormatDate(std::string line);
    void                            outputResult(void);
    void                            execute(const char *file_input);
    BitcoinExchange &operator=(BitcoinExchange const &rhs);

    //class dateFormatExeption: std::exception {const char *what() const throw() {return "BTC has been create in 2009 bro, so what do you want to check ? mdrr";};};
private:
    std::map<std::string, float>    _data;
    std::string                     _dataKeyValue;
    float                           _dataValue;

    std::map<std::string, float>    _mapInput;
    std::string                     _inputKeyValue;
    float                           _inputValue;
};

std::ostream &operator<<(std::ostream &o, BitcoinExchange const &i);

int     dateFormat(std::string line);
int     checkValue(std::string line);
bool    isLeapYear(int year);
/*std::map<std::string, float>::iterator it;
    std::map<std::string, float>::iterator ite = this->_data.end();
    for (it = this->_data.begin(); it != ite; it++) {
        std::cout<< std::fixed << std::setprecision(2)
        << "_data[" << it->first << "] = " << it->second << std::endl;
    }*/
#endif