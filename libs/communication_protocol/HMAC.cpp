/*
 * HMAC.cpp
 *
 *  Created on: 15/10/2013
 *      Author: juan
 */


//sudo apt-get install libssl-dev
//-lssl -lcrypto
#include "HMAC.h"
#include <openssl/sha.h> //SHA1
#include <string>
#include <sstream>

// unsigned char *SHA1(const unsigned char *d, unsigned long n,
//                 unsigned char *md);

#define IPAD 0x36
#define OPAD 0x5c

void mySHA1(const std::string msg, unsigned char * digest){
//	digest.clear();
//	digest.resize(SHA_DIGEST_SIZE);
//	unsigned char c_digest[SHA_DIGEST_SIZE];
	//Hago el casteo tranquilo porque ningun ASCII es negativo
	SHA1((unsigned char *)msg.c_str(), msg.size(), digest);
}

void stringXor (std::string & s, const char key){
	char * c_str = (char *)s.c_str();
	for (unsigned i = 0; i < s.size(); i++){
		//Hace el xor a cada byte
		*( c_str + i) = (*(c_str + i)) ^ key;
	}
}

void HMAC(std::string key, std::string msg, unsigned char * digest){
	std::stringstream ss;
	//Prepara la inner key
	std::string i_key = key;
	stringXor(i_key, IPAD);
	ss << i_key;
	ss << msg;
	//hashea inner key + msg
	unsigned char SHA1_digest[SHA_DIGEST_SIZE];
	mySHA1(ss.str(), SHA1_digest);
	//borra el stream
	ss.str(std::string());
	ss.clear();
	//prepara outer key
	std::string o_key = key;
	stringXor(o_key, OPAD);
	ss << o_key;
	ss.write((char *)SHA1_digest, SHA_DIGEST_SIZE);
	//hashea outer key + msg
	mySHA1(ss.str(), digest);
}

void HMACSignedMsg(std::string & msg, std::string key){
	unsigned char digest[SHA_DIGEST_SIZE];
	HMAC(key, msg, digest);
	char * signed_digest = (char*) digest;
	msg.append(signed_digest, SHA_DIGEST_SIZE);
}

bool checkSignedMsg(std::string signed_msg, std::string key){
	if (signed_msg.size() < SHA_DIGEST_SIZE) return false;
	std::string msg = signed_msg.substr(0, signed_msg.size() - SHA_DIGEST_SIZE);
	//digest va desde signed_msg.size() - SHA_DIGEST_SIZE hasta el final
	std::string digest = signed_msg.substr(signed_msg.size() - SHA_DIGEST_SIZE);
	HMACSignedMsg(msg, key);
	std::string new_digest = msg.substr(msg.size() - SHA_DIGEST_SIZE);
	return (digest.compare(new_digest) == 0);
}

