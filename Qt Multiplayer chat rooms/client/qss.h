#ifndef QSS_H
#define QSS_H
 QString lineEditStyle =
    " QLineEdit {"
    "   background-color: #ffffff;"
    "   border: 1px solid #c4c4c3;"
    "   padding: 3px;"
    "   font-size: 24px;"
    "   color: #333333;"
    "   border-radius: 4px;"
    "   transition: border-color 0.2s ease-in-out;"
    "}"
    "QLineEdit:hover {"
    "   border-color: #6ca0d1;"
    "}"
    "QLineEdit:focus {"
    "   border-color: #3d84b6;"
    "   outline: none;"
    "   box-shadow: inset 0 0 2px #3d84b6, 0 0 8px rgba(61, 132, 182, 0.5);"
    "}"
    "QLineEdit[invalid=true] {"
    "   border-color: #ff4d4d;"
    "}";



#endif // QSS_H
