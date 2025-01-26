// void BitcoinExchange::exchange(std::ifstream &file)
// {
// 	std::string input;
// 	std::getline(file, input);
// 	if (input != "date | value")
// 		throw InvalidDataFormatError();
		
// 	_addExchangeRateAndDatesToMap();
	
// 	while (std::getline(file, input))
// 	{
// 		try
// 		{
// 			std::string date = input.substr(0, input.find('|') - 1);
// 			std::string value = input.substr(input.find('|') + 2);

// 			if (date.empty() || value.empty())
// 				throw InvalidDataFormatError();
// 			if (!_validateDate(date))
// 				throw InvalidDataFormatError();
// 			double numValue = std::strtod(value.c_str(), NULL);
// 			if (numValue <= 0 || numValue > 1000)
// 				throw OutOfRangeError();

// 			std::string concateDate = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2);

// 			std::map<std::string, double>::iterator it = _exchangeRate.lower_bound(concateDate);

// 			if (it == _exchangeRate.end() || it->first != concateDate) 
// 			{
// 				if (it == _exchangeRate.begin())
// 					throw InvalidDataFormatError();
// 				--it;
// 			}

// 			std::cout << date << " => " << value << " = " 
// 					<< std::fixed << std::setprecision(2) 
// 					<< std::strtod(value.c_str(), NULL) * it->second << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what();
// 		}
// 	}
// }
