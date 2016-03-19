#ifndef STDXML_H
#define	STDXML_H
#include <vector>
#include <fstream>
#include <string>

using std::string;

namespace mc
{
    namespace xml
    {
        struct attribute
        {
            string name, value;
            attribute(string& name_, string& value_);
            string toString() const;
        };

        struct element
        {
            string name, value;
            element* parent;
            std::vector<attribute*> attributes;
            std::vector<element*> childs;
            element(string name_ = "element");
            ~element();
            void appendChild(element* element_);
            string getAttribute(const string name_);
            void setAttribute(string name_, string value_);
            element* getElementById(const string& value);
            std::vector<element*> getElementsByTagName(const string& name_);
            string toString();
            element* firstChild();
            element* lastChild();
            bool removeChild(element* old);
            bool insertAfter(element* child, element* element_);
        };

        struct document
        {
            element parent;
            element* getElementById(const string& value);
            std::vector<element*> getElementsByTagName(const string& name_);
            string toString();
            document(string rootName = "root");
            ~document();
            void load(std::ifstream& fin);
            void loadXml(string& xml);
            element* createElement(const string& name);
        };
    }
}

#endif	/* STDXML_H */

