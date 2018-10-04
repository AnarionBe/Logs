# Logs
Small class to debbug and log C++ application.

Constructors

  Logs() -> Will activate the debbug messages in the terminal and write logs into ./logs.dblogs file
  
  Logs(string f, bool b)
  
    f -> path of the log file
    
    b -> set the debbug mode. True to display debbug messages
   
   
 Methods
 
  ShowDebbug(bool b) -> Will change the debbug mode
  
    b -> mode wanted. True to display debbug messages
    
  Debbug(...) -> Allow to display debbug message. Same syntax as printf()
  
  Log(...) -> Allow to write a log line. Same syntax as printf()
