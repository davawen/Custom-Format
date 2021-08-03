#pragma once

class KeyValue
{
	private:
		bool _isObject;
		
	public:
		const char *key;
		/// Can either be a char*, an int, or a KeyValue
		void *value;
		
		KeyValue();
		KeyValue(const char *key, void *value, bool isObject);
		
		KeyValue(KeyValue &&other);
		
		~KeyValue();
		
		bool isObject();
};