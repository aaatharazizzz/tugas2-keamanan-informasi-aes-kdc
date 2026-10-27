#pragma once
#include <span>
#include <array>
#include <cinttypes>
#include <vector>
#include <stdexcept>
#include <optional>

enum class AESType {
    AES128,
    AES192,
    AES256,
};


enum class AESBlockMode {
    ECB,
    CBC
};

class AESRoundKeys {
public:
    AESRoundKeys(AESType aes_type);
};

class AESBlock {
private:
    std::array<uint8_t, 16> bytes;
public:
    void shift_rows();
    void mix_columns();
    void add_round_key();
};

std::array<uint8_t, 16> aes_generate_iv();

class AES {
private:
    std::vector<uint8_t> key;
    AESType type;
    AESBlockMode mode;
public:
    AES(std::span<uint8_t> key, AESType type, AESBlockMode mode) : key(key.begin(), key.end()), type(type), mode(mode) {
        if(this->type == AESType::AES128 && this->key.size() != 16) {
            throw std::length_error("Key size mismatch (AES128 key size not 16 bytes)");
        } else if(this->type == AESType::AES192 && this->key.size() != 24) {
            throw std::length_error("Key size mismatch (AES196 key size not 24 bytes)");
        } else if(this->type == AESType::AES256 && this->key.size() != 32) {
            throw std::length_error("Key size mismatch (AES256 key size not 32 bytes)");
        }
    }
    std::vector<uint8_t> encrypt(std::span<const uint8_t> plaintext, std::array<uint8_t, 16> iv = aes_generate_iv());
};