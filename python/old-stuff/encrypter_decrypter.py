##########################################
## Multiplication Encrypter & Decrypter ##
## ckjbgames #############################
## 2016 ##################################
##########################################

## Imports
import string
## Constants
prompt_choice = 'Encrypt (e) or decrypt (d)? '
prompt_phrase = ['What is the message to be encrypted? ','What is the message to be decrypted? ']
message_show = 'The message is: '
reenter = 'Please reenter.'
## Functions
#### For both encryption and decryption
def make_ascii_list(plain):
    some_list = []
    for char in plain:
        asciival = ord(char)
        some_list.append(asciival)
    return some_list
def ascii_to_text(ascii_list):
    spam_list = []
    for something in ascii_list:
        spam = unichr(something)
        spam_list.append(spam)
    return ''.join(spam_list)
#### Encryption
def encrypt(a_list,prime_list):
    new_list = []
    spam = -1
    for value in a_list:
        spam = spam + 1
        new_value = (value + 1) * prime_list[spam]
        new_list.append(new_value)
    return new_list
#### Decryption
def decrypt(a_list,prime_list):
    new_list = []
    spam = -1
    for value in a_list:
        spam = spam + 1
        new_value = (value - 1) / prime_list[spam]
        new_list.append(new_value)
    return new_list
## Now, the real thing
boolean = False
while boolean == False:
    choice = raw_input(prompt_choice)
    part_choice = choice[0:1] 
    if part_choice == 'e' or part_choice == 'E' or part_choice == 'd' or part_choice == 'D':
        boolean = True
    else:
        print reenter
if part_choice == 'e' or part_choice == 'E':
    phrase = raw_input(prompt_phrase[0])
    thelist = [spam for spam in range(1,len(phrase * 2) + 1) if spam % 2 > 0]
    ascii_list = make_ascii_list(phrase)
    cipherlist = encrypt(ascii_list,thelist)
    ciphertext = ascii_to_text(cipherlist)
    print message_show
    print ciphertext
elif part_choice == 'd' or part_choice == 'D':
    phrase = raw_input(prompt_phrase[1])
    thelist = [spam for spam in range(1,len(phrase * 2) + 1) if spam % 2 > 0]
    ascii_list = make_ascii_list(phrase)
    plainlist = decrypt(ascii_list,thelist)
    plaintext = ascii_to_text(plainlist)
    print message_show
    print plaintext
