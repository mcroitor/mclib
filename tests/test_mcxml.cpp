
/* 
 * File:   test_mcxml.cpp
 * Author: Krey
 *
 * Created on August 10, 2017, 3:58 PM
 */

#include <stdlib.h>
#include <iostream>
#include "mcxml.h"

/*
 * Simple C++ Test Suite
 */

using namespace mc::xml;

void testGetElementById() {
    const string& value = "header";
    mc::xml::document _document;
    element* result = _document.getElementById(value);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testGetElementById (test_mcxml) message=error message sample" << std::endl;
    }
}

void testGetElementsByTagName() {
    const string& name_ = "a";
    mc::xml::document _document;
    std::vector<element*> result = _document.getElementsByTagName(name_);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testGetElementsByTagName (test_mcxml) message=error message sample" << std::endl;
    }
}

void testToString() {
    mc::xml::document _document;
    string result = _document.toString();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testToString (test_mcxml) message=error message sample" << std::endl;
    }
}

void testDocument() {
    string rootName("root");
    mc::xml::document _document(rootName);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testDocument (test_mcxml) message=error message sample" << std::endl;
    }
}

void testLoad() {
    std::ifstream fin("example.xml");
    mc::xml::document _document;
    _document.load(fin);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testLoad (test_mcxml) message=error message sample" << std::endl;
    }
}

void testLoadXml() {
    string xml = "<root><element>test</element><element>test2</element></root>";
    mc::xml::document _document;
    _document.loadXml(xml);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testLoadXml (test_mcxml) message=error message sample" << std::endl;
    }
}

void testCreateElement() {
    const string& name = "newElement";
    mc::xml::document _document;
    element* result = _document.createElement(name);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testCreateElement (test_mcxml) message=error message sample" << std::endl;
    }
}

void testName() {
    mc::xml::element _element;
    const string result = _element.name();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testName (test_mcxml) message=error message sample" << std::endl;
    }
}

void testValue() {
    mc::xml::element _element;
    _element.value("value");
    const string result = _element.value();
    if (result != "value") {
        std::cout << "%TEST_FAILED% time=0 testname=testValue (test_mcxml) message=error message sample" << std::endl;
    }
}

void testValue2() {
    string p0 = "value2";
    mc::xml::element _element;
    _element.value(p0);
    if (_element.value() != p0) {
        std::cout << "%TEST_FAILED% time=0 testname=testValue2 (test_mcxml) message=error message sample" << std::endl;
    }
}

void testElement() {
    string name_ = "element";
    mc::xml::element _element(name_);
    if (_element.name() != name_) {
        std::cout << "%TEST_FAILED% time=0 testname=testElement (test_mcxml) message=error message sample" << std::endl;
    }
}

void testAppendChild() {
    element* element_ = new element("child");
    mc::xml::element _element("parent");
    _element.appendChild(element_);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testAppendChild (test_mcxml) message=error message sample" << std::endl;
    }
}

void testGetAttribute() {
    const string name_ = "attribute";
    mc::xml::element _element("element");
    _element.setAttribute(name_, "value");
    string result = _element.getAttribute(name_);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testGetAttribute (test_mcxml) message=error message sample" << std::endl;
    }
}

void testSetAttribute() {
    string name_ = "attribute";
    string value_ = "value";
    mc::xml::element _element;
    _element.setAttribute(name_, value_);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSetAttribute (test_mcxml) message=error message sample" << std::endl;
    }
}

void testGetElementById2() {
    const string& value = "child01";
    mc::xml::element _element("element");
    element* result = _element.getElementById(value);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testGetElementById2 (test_mcxml) message=error message sample" << std::endl;
    }
}

void testGetElementsByTagName2() {
    const string& name_ = "a";
    mc::xml::element _element;
    std::vector<element*> result = _element.getElementsByTagName(name_);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testGetElementsByTagName2 (test_mcxml) message=error message sample" << std::endl;
    }
}

void testToString2() {
    mc::xml::element _element("element");
    _element.value("value");
    string result = _element.toString();
    std::cout << result << std::endl;
    if (result != "<element>value</element>") {
        std::cout << "%TEST_FAILED% time=0 testname=testToString2 (test_mcxml) message=error message sample" << std::endl;
    }
}

void testFirstChild() {
    mc::xml::element _element;
    element* result = _element.firstChild();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testFirstChild (test_mcxml) message=error message sample" << std::endl;
    }
}

void testLastChild() {
    mc::xml::element _element;
    element* result = _element.lastChild();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testLastChild (test_mcxml) message=error message sample" << std::endl;
    }
}

void testRemoveChild() {
    element* old;
    mc::xml::element _element;
    bool result = _element.removeChild(old);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testRemoveChild (test_mcxml) message=error message sample" << std::endl;
    }
}

void testInsertAfter() {
    element* child = new element("child01");
    element* element_ = new element("child02");
    mc::xml::element _element("parent");
    _element.appendChild(child);
    bool result = _element.insertAfter(child, element_);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertAfter (test_mcxml) message=error message sample" << std::endl;
    }
}

void testAttribute() {
    const string& name_ = "href";
    const string& value_ = "http://google.com";
    mc::xml::attribute _attribute(name_, value_);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testAttribute (test_mcxml) message=error message sample" << std::endl;
    }
}

void testToString3() {
    mc::xml::attribute _attribute("href", "http://google.com");
    string result = _attribute.toString();
    if (result != "href='http://google.com'") {
        std::cout << "%TEST_FAILED% time=0 testname=testToString3 (test_mcxml) message=error message sample" << std::endl;
    }
}

void testName2() {
    mc::xml::attribute _attribute("attr", "value");
    const string result = _attribute.name();
    if (result != "attr") {
        std::cout << "%TEST_FAILED% time=0 testname=testName2 (test_mcxml) message=error message sample" << std::endl;
    }
}

void testValue3() {
    mc::xml::attribute _attribute("attr", "value");
    const string result = _attribute.value();
    if (result != "value") {
        std::cout << "%TEST_FAILED% time=0 testname=testValue3 (test_mcxml) message=error message sample" << std::endl;
    }
}

void testValue4() {
    string p0 = "value2";
    mc::xml::attribute _attribute("attr", "value");
    _attribute.value(p0);
    if (_attribute.value() != "value2") {
        std::cout << "%TEST_FAILED% time=0 testname=testValue4 (test_mcxml) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% test_mcxml" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testGetElementById (test_mcxml)" << std::endl;
    testGetElementById();
    std::cout << "%TEST_FINISHED% time=0 testGetElementById (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testGetElementsByTagName (test_mcxml)" << std::endl;
    testGetElementsByTagName();
    std::cout << "%TEST_FINISHED% time=0 testGetElementsByTagName (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testToString (test_mcxml)" << std::endl;
    testToString();
    std::cout << "%TEST_FINISHED% time=0 testToString (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testDocument (test_mcxml)" << std::endl;
    testDocument();
    std::cout << "%TEST_FINISHED% time=0 testDocument (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testLoad (test_mcxml)" << std::endl;
    //testLoad();
    std::cout << "skip test" << std::endl;
    std::cout << "%TEST_FINISHED% time=0 testLoad (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testLoadXml (test_mcxml)" << std::endl;
    testLoadXml();
    //std::cout << "skip test" << std::endl;
    std::cout << "%TEST_FINISHED% time=0 testLoadXml (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testCreateElement (test_mcxml)" << std::endl;
    testCreateElement();
    std::cout << "%TEST_FINISHED% time=0 testCreateElement (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testName (test_mcxml)" << std::endl;
    testName();
    std::cout << "%TEST_FINISHED% time=0 testName (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testValue (test_mcxml)" << std::endl;
    testValue();
    std::cout << "%TEST_FINISHED% time=0 testValue (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testValue2 (test_mcxml)" << std::endl;
    testValue2();
    std::cout << "%TEST_FINISHED% time=0 testValue2 (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testElement (test_mcxml)" << std::endl;
    testElement();
    std::cout << "%TEST_FINISHED% time=0 testElement (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testAppendChild (test_mcxml)" << std::endl;
    testAppendChild();
    std::cout << "%TEST_FINISHED% time=0 testAppendChild (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testGetAttribute (test_mcxml)" << std::endl;
    testGetAttribute();
    std::cout << "%TEST_FINISHED% time=0 testGetAttribute (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testSetAttribute (test_mcxml)" << std::endl;
    testSetAttribute();
    std::cout << "%TEST_FINISHED% time=0 testSetAttribute (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testGetElementById2 (test_mcxml)" << std::endl;
    testGetElementById2();
    std::cout << "%TEST_FINISHED% time=0 testGetElementById2 (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testGetElementsByTagName2 (test_mcxml)" << std::endl;
    testGetElementsByTagName2();
    std::cout << "%TEST_FINISHED% time=0 testGetElementsByTagName2 (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testToString2 (test_mcxml)" << std::endl;
    testToString2();
    std::cout << "%TEST_FINISHED% time=0 testToString2 (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testFirstChild (test_mcxml)" << std::endl;
    testFirstChild();
    std::cout << "%TEST_FINISHED% time=0 testFirstChild (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testLastChild (test_mcxml)" << std::endl;
    testLastChild();
    std::cout << "%TEST_FINISHED% time=0 testLastChild (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testRemoveChild (test_mcxml)" << std::endl;
    testRemoveChild();
    std::cout << "%TEST_FINISHED% time=0 testRemoveChild (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testInsertAfter (test_mcxml)" << std::endl;
    testInsertAfter();
    std::cout << "%TEST_FINISHED% time=0 testInsertAfter (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testAttribute (test_mcxml)" << std::endl;
    testAttribute();
    std::cout << "%TEST_FINISHED% time=0 testAttribute (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testToString3 (test_mcxml)" << std::endl;
    testToString3();
    std::cout << "%TEST_FINISHED% time=0 testToString3 (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testName2 (test_mcxml)" << std::endl;
    testName2();
    std::cout << "%TEST_FINISHED% time=0 testName2 (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testValue3 (test_mcxml)" << std::endl;
    testValue3();
    std::cout << "%TEST_FINISHED% time=0 testValue3 (test_mcxml)" << std::endl;

    std::cout << "%TEST_STARTED% testValue4 (test_mcxml)" << std::endl;
    testValue4();
    std::cout << "%TEST_FINISHED% time=0 testValue4 (test_mcxml)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

