#include "key.hpp"

KeyValue::KeyValue()
{
	this->key = "";
	this->value = nullptr;
	this->_isObject = false;
}

KeyValue::KeyValue(const char *key, void *value, bool isObject)
{
	this->key = key;
	this->value = value;
	this->_isObject = isObject;
}

KeyValue::KeyValue(KeyValue &&other)
{
	this->key = other.key;
	this->value = other.value;
	
	other.value = nullptr;
}

KeyValue::~KeyValue()
{
	if(_isObject) delete[] value;
	else delete value;
}

bool KeyValue::isObject()
{
	return _isObject;
}