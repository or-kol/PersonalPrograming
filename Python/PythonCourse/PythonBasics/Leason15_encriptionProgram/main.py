import random
import string


chars = " " + string.punctuation + string.ascii_letters + string.digits

chars = list(chars)

key = chars.copy()
random.shuffle(key)


'''
print(chars)
print(key)
'''

#Encrypt
original_message = input("Enter a message to encrypt: ")
cipher_message = ""

for char in original_message:
    cipher_message += key[chars.index(char)]


#Decrypt
decrypt_message = ""

for char in cipher_message:
    decrypt_message += chars[key.index(char)]

print(cipher_message)
print(decrypt_message)











def main():
    pass


if __name__ == "__main__":
    main()