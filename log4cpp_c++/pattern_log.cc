#include <iostream>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>

int main(){
	log4cpp::OstreamAppender *appender = 
		new log4cpp::OstreamAppender("app",&std::cout);
	
	log4cpp::PatternLayout *pLayout = new log4cpp::PatternLayout();
	//设置格式
	pLayout->setConversionPattern("%d : %p %c %x : %m %n");
	
	appender->setLayout(pLayout);
	
	log4cpp::Category &root = log4cpp::Category::getRoot();
	log4cpp::Category &infoCate = log4cpp::Category::getInstance("info");
	
	root.setPriority(log4cpp::Priority::INFO);
	//不能有两个Category同时添加Appender,否则发生段错误
	//root.addAppender(appender);
	
	infoCate.setPriority(log4cpp::Priority::WARN);
	infoCate.addAppender(appender);
	#if 0
	root.info("info");
	root.debug("debuf");
	root.warn("warn");
	root.error("error");
	root.fatal("fatal");
	#endif
	infoCate.info("info cate");
	infoCate.debug("debug cate");
	infoCate.warn("warn cate");
	infoCate.error("error cate");
	infoCate.fatal("fatal cate");

	log4cpp::Category::shutdown();
	return 0;
}
