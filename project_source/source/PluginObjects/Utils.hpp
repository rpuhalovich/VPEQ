// created by Ryan Puhalovich - http://github.com/rpuhalovich
// utility functions that I may need

#pragma once

#ifdef RELEASE
    #define DEBUG_PRINT(msg_str, var)
#else
    #define DEBUG_PRINT(msg_str, var) std::cout << msg_str << var << std::endl
#endif // DEBUG
