class FileReadException : public exception
{
	public:
		FileReadException(const string &message, bool inclSysMsg = false) throw();
		~FileReadException() throw();
		const char *what() const throw();

	private:
		string userMessage;
};

