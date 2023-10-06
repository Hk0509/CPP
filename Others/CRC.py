def xor(a, b):
    result=""
    for i in range(len(b)):
        result=result+str(int(a[i])^int(b[i]))
    return result

def mod2div(dividend, divisor):
    dividend=dividend
    pick=len(divisor)
    tmp=dividend[0:pick]

    while(True):
        if tmp[0]=="1":
            tmp=xor(divisor, tmp)
        else:
            tmp=xor("0"*pick, tmp)

        tmp=tmp[1::]+dividend[pick]
        pick+=1

        if(pick>=len(dividend)):
            if tmp[0]=="1":
                tmp=xor(divisor, tmp)
            else:
                tmp=xor("0"*pick, tmp)
            tmp=tmp[1::]
            break

    return tmp

def encodeData(data, divisor, real_data):
    remainder=mod2div(data, divisor)
    codeword=real_data+remainder
    print("CRC bits: ", remainder)
    print("Transmitted Data:", codeword)
    return codeword

def decodeData(received_Data, divisor):
    remainder=mod2div(received_Data, divisor)
    print("Remainder: ", remainder)
    remainder=int(remainder,2)
    if remainder!=0:
        print("Since remainder is not equal to 0, the message received is in-correct!!!")
    else:
        print("Since remainder is 0, the message received is correct!!!")

len_data=int(input("Enter the length of the data: "))
data=input("Enter the data: ")
real_data=data
len_Divisor=int(input("Enter the length of the Generator (Divisor): "))
divisor=input("Enter the Generator(Divisor): ")
print("Number of 0's to be appended: ", (len_Divisor - 1))
data=data+"0"*(len_Divisor-1)
print("Message after appending 0's: ", data)
encodeData(data, divisor, real_data)
received_Data=input("Enter the Received Data: ")
decodeData(received_Data, divisor)
