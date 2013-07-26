#include "addressbook.h"

Contact::Contact() {
  set_name("unnamed");
  set_phone_number("000-000-0000");
}

void Contact::set_name(string name) {
  name_ = name;
}

void Contact::set_phone_number(string phone_number) {
  phone_number_ = phone_number;
}

string Contact::name() const {
  return name_;
}

string Contact::phone_number() const {
  return phone_number_;
}

AddressBook::AddressBook() {
  contacts_ = vector<Contact>();
}

vector<Contact> AddressBook::contacts() const {
  return contacts_;
}


void AddressBook::AddPerson(string name, string phone_number) {
  Contact contact = Contact();
  contact.set_name(name);
  contact.set_phone_number(phone_number);
  contacts_.push_back(contact);
}

AddressBook AddressBook::JsonCreate(string filename) {
  AddressBook address_book = AddressBook();
  address_book.JsonLoad(filename);
  return address_book;
}

void AddressBook::JsonSave(string filename) {  
  for (vector<Contact>::iterator it = contacts_.begin(); it != contacts_.end(); ++it) {
    Json::Value value(Json::objectValue);
    //out << value;
  }
}

void AddressBook::JsonLoad(string filename) {
}
