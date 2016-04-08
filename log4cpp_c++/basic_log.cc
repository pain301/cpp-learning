#include <iostream>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>

int main(){
	//Appender
	log4cpp::OstreamAppender *appender 
		= new log4cpp::OstreamAppender("OsApp",&std::cout);
	appender->setLayout(new log4cpp::BasicLayout());

	//Category
	log4cpp::Category &root = log4cpp::Category::getRoot();
	root.addAppender(appender);

	//Priority
	root.setPriority(log4cpp::Priority::WARN);

	root.debug("debug");
	root.error("error!!!");
	root.warn("warn!!!");
	
	//关闭
	log4cpp::Category::shutdown();
	return 0;
}
