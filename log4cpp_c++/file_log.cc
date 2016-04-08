#include <iostream>
#include <string>
#include <sstream>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>

int main(){
	//FileAppender
	log4cpp::FileAppender *fileApp 
		= new log4cpp::FileAppender("fileApp","file.log");
	log4cpp::PatternLayout *pLayout1 = new log4cpp::PatternLayout();
	pLayout1->setConversionPattern("%d : %p %c %x : %m %n");
	fileApp->setLayout(pLayout1);
	
	//RollingFileAppender
	log4cpp::RollingFileAppender *rollFileApp
		= new log4cpp::RollingFileAppender("rollApp","roll.log",5*1024,1);
	log4cpp::PatternLayout *pLayout2 = new log4cpp::PatternLayout();
	pLayout2->setConversionPattern("%d : %p %c %x : %m %n");
	rollFileApp->setLayout(pLayout2);

	//Appender分别用自己的layout
	log4cpp::Category & root = log4cpp::Category::getRoot().getInstance("root");
	root.addAppender(fileApp);
	root.addAppender(rollFileApp);
	root.setPriority(log4cpp::Priority::WARN);
	
	for(int i = 0;i<100;i++){
		std::ostringstream ostr;
		ostr<<"error "<<i<<" message"<<std::endl;
		std::cout<<ostr.str()<<std::endl;
		root.error(ostr.str());
	}
	
	log4cpp::Category::shutdown();

	return 0;
}
