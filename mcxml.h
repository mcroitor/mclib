#ifndef STDXML_H
#define STDXML_H
#include <vector>
#include <fstream>
#include <string>

using std::string;

namespace mc {
    namespace xml {

        class attribute {
            string _name, _value;
        public:
            attribute(string& name_, string& value_);
            string toString() const;
            const string name() const;
            const string value() const;
            void value(string);
        };

        class element {
            string _name, _value;
            element* parent;
            std::vector<attribute*> attributes;
            std::vector<element*> childs;
        public:
            const string name() const;
            const string value() const;
            void value(string);
            
            element(string name_ = "element");
            ~element();
            void appendChild(element* element_);
            string getAttribute(const string name_);
            void setAttribute(string name_, string value_);
            element* getElementById(const string& value);
            std::vector<element*> getElementsByTagName(const string& name_);
            string toString() const;
            element* firstChild();
            element* lastChild();
            bool removeChild(element* old);
            bool insertAfter(element* child, element* element_);
        };

        class document {
            element parent;
        public:
            element* getElementById(const string& value);
            std::vector<element*> getElementsByTagName(const string& name_);
            string toString() const;
            document(string rootName = "root");
            ~document();
            void load(std::ifstream& fin);
            void loadXml(string& xml);
            element* createElement(const string& name);
        };
    }
}

#endif /* STDXML_H */

