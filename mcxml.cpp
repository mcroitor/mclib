#include "mcxml.h"
#include "algebra/biginteger.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>

namespace mc {
    namespace xml {

        struct checker {
            string name;

            explicit checker(const string& n) : name(n) {
            }

            bool operator()(attribute* attr) const {
                if (name == attr->name())
                    return true;
                return false;
            }
        };

        attribute::attribute(const string& name_, const string& value_)
        : _name(name_), _value(value_) {
        }

        const string attribute::name() const {
            return _name;
        }

        const string attribute::value() const {
            return _value;
        }

        void attribute::value(string v) {
            _value = v;
        }

        string attribute::toString() const {
            string result(this->name());
            result.append("='");
            result.append(this->value());
            result.append("'");
            return result;
        }

        element::element(string name_) : _name(name_), parent(nullptr) {
            string tmp(_name), aux("id");
            char* _value = new char[255];

            sprintf(_value, "%d", rand());
            tmp.append("_");
            tmp.append(_value);
            this->attributes.push_back(new attribute(aux, tmp));
            delete[] _value;
        }

        const string element::name() const {
            return _name;
        }

        const string element::value() const {
            return _value;
        }

        void element::value(string v) {
            _value = v;
        }

        void element::appendChild(element* element_) {
            // TODO #: throw clear exception!
            if (element_ == nullptr) {
                throw std::exception();
            }
            element_->parent = this;
            this->childs.push_back(element_);
        }

        string element::getAttribute(const string name_) {
            std::vector<attribute*>::iterator i;
            i = std::find_if(attributes.begin(), attributes.end(), checker(name_));
            if (i != attributes.end())
                return (*i)->value();
            throw std::exception();
        }

        void element::setAttribute(string name_, string value_) {
            std::vector<attribute*>::iterator i;
            i = std::find_if(attributes.begin(), attributes.end(), checker(name_));
            if (i != attributes.end()) {
                (*i)->value(value_);
            } else {
                attributes.push_back(new attribute(name_, value_));
            }
        }

        element* element::getElementById(const string& _value) {
            element* result = nullptr;
            if (this->getAttribute("id").compare(_value) == 0) {
                result = this;
            } else {
                std::vector<element*>::iterator i = childs.begin();
                while (result == nullptr && i != childs.end()) {
                    result = (*i)->getElementById(_value);
                    ++i;
                }
            }
            return result;
        }

        std::vector<element*> element::getElementsByTagName(const string& name_) {
            std::vector<element*> result;
            std::vector<element*>::const_iterator i;
            for (i = childs.begin(); i != childs.end(); ++i) {
                if ((*i)->name() == name_) {
                    result.push_back(*i);
                }
                std::vector<element*>::iterator j;
                for (
                        j = (*i)->getElementsByTagName(name_).begin();
                        j != (*i)->getElementsByTagName(name_).end();
                        ++j) {
                    result.insert(result.end(), *j);
                }
            }

            return result;
        }

        string element::toString() const {
            string result("");
            result.append("<");
            result.append(this->_name);
            if (!attributes.empty()) {
                std::vector<attribute*>::const_iterator i;
                for (i = attributes.begin(); i != attributes.end(); ++i) {
                    result.append(" ");
                    result.append((*i)->toString());
                }
            }
            result.append(">");
            if (!childs.empty()) {
                std::vector<element*>::const_iterator i;
                for (i = childs.begin(); i != childs.end(); ++i) {
                    result.append("\n\t");
                    result.append((*i)->toString());
                }
                result.append("\n");
            }
            result.append("</");
            result.append(this->_name);
            result.append(">");
            return result;
        }

        element* element::firstChild() {
            element* result = nullptr;
            if (!childs.empty())
                result = childs.front();
            return result;
        }

        element* element::lastChild() {
            element* result = nullptr;
            if (!childs.empty())
                result = childs.back();
            return result;
        }

        element* document::getElementById(const string& value) {
            return parent.getElementById(value);
        }

        std::vector<element*> document::getElementsByTagName(const string& name_) {
            return parent.getElementsByTagName(name_);
        }

        element::~element() {
            while (attributes.size() != 0) {
                attribute* tmp = attributes.back();
                attributes.pop_back();
                delete tmp;
            }
            while (childs.size() != 0) {
                element* aux = childs.back();
                childs.pop_back();
                delete aux;
            }
        }

        bool element::removeChild(element* old) {
            if (old == nullptr)
                return false;
            if (old->parent != this)
                return false;
            std::vector<element*>::iterator i = std::find(childs.begin(), childs.end(), old);
            childs.erase(i);
            delete old;
            return true;
        }

        bool element::insertAfter(element* child, element* element_) {
            if (element_ == nullptr)
                return false;
            if (child == nullptr) {
                childs.push_back(element_);
                return true;
            }
            if (child->parent != this) {
                return false;
            }
            std::vector<element*>::iterator i = std::find(childs.begin(), childs.end(), child);
            childs.insert(i, element_);
            return true;
        }

        string document::toString() const {
            return parent.toString();
        }

        document::document(string rootName) : parent(rootName) {
        }

        document::~document() {
        }

        void document::load(std::ifstream& fin) {
            string xml, tmp;
            while (!fin.eof()) {
                fin >> tmp;
                xml.append(tmp);
            }
            loadXml(xml);
        }

        void document::loadXml(string& xml) {

        }

        element* document::createElement(const string& name) {
            return new element(name);
        }
    }
}
