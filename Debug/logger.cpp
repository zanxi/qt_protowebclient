#include "logger.h"    

    long logger::cnt = 0;

    std::string logger::CreateLogName(){        

        return Num::fn;       
        //return "log_debug_"+ datetime::utcExample()+ ".txt";
    }

    void logger::ClearLog(std::string fn){        
       fn=CreateLogName();
       std::cout<<"<<<<<<<<<<<Clear log>>>>>>>>>>>"<<"\n";
       std::ofstream out;    
       //out.open(fn,std::ios::app);
       fn=Num::fn;
       out.open(fn);    
       out.close();
    }

    void logger::WriteMsg(std::string msg, std::string fn){
       //return;
        fn=CreateLogName();
    std::ofstream out;    
    out.open(fn,std::ios::app);
    //out.open(fn);
    if(out.is_open())
    {        
        out<<(cnt++)<<" | "<<datetime::utcExample()<<"| message: "<<msg<<"  "<<"\n";        
    }
    out.close();
    }

    void logger::WriteMsgError(std::string msg, std::string fn){        
        fn=CreateLogName();
    std::ofstream out;    
    out.open(fn,std::ios::app);
    //out.open(fn);
    if(out.is_open())
    {   
        out<<(cnt++)<<" | "<<
        datetime::utcExample()
        <<" | ******* | Error information: "<<msg<<"  "<<"\n";        
    }
    out.close();
    }

    void logger::SaveEndMsgNumber(std::string fn){        
        fn=CreateLogName();
    std::ofstream out;    
    //out.open(fn,std::ios::app);
    out.open(fn);
    if(out.is_open())
    {        
        out<<cnt<<"\n";        
    }
    out.close();
    }

    void logger::ReadEndMsgNumber(std::string fn)
    {        
        fn=CreateLogName();
    ifstream in2(fn);
    if(in2.is_open())
    {
                
        while(in2>>cnt)
        {                        
            //cout<<w<<") | x="<<x<<"; y="<<y<<"\n";
        }
    }
    else
    {
        cnt=0;
    }
    in2.close();    
    }

    void logger::WriteSqlScript(std::string msg, std::string fn)
    {
        fn=CreateLogName();        
    std::ofstream out;    
    out.open(fn,std::ios::app);
    //out.open(fn);
    if(out.is_open())
    {   
        //out<<(cnt++)<<" | "<<datetime::utcExample()<<" | *************************************** | Error information: "<<msg<<"  "<<"\n";        
        out<<msg<<"  "<<"\n";        
    }
    out.close();
    }
