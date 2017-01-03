class person{
	protected:

		char * m_sName;
		int m_nId;

		void setinfo(int id, const char * name);
		void show();

	public:
		
		person(){}
		~person(){
//			if(m_sName != nullptr)
				delete[] m_sName;
		}
};

class teacher : public person{
	private:
		
		char * m_sDepartment;
		char * m_sPosition;

	public:

		teacher(){}
		~teacher(){
			delete[] m_sDepartment;
			delete[] m_sPosition;
		}
		void setinfo(
				int id,
				const char * name,
				const char * department,
				const char * position
				);
		void show();
};

class student : public person{
	private:

		int m_nScore;
		int m_nClassId;

	public:

		void setinfo(
			int id,
			const char * name,
			int classid,
			int score
			);
		void show();
};
