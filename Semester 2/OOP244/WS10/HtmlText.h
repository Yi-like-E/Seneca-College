#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include <iostream>
#include "Text.h"
using namespace std;
namespace sdds {
class HtmlText :  public Text {
    char* m_title;
public:
    HtmlText(const char* filename=nullptr, const char* title = nullptr);
    HtmlText(const HtmlText&);
    HtmlText& operator=(const HtmlText& source);
    ~HtmlText();
    void write(ostream& os)const;
};
}
#endif // !SDDS_HTMLTEXT_H__
