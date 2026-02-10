#include <stdio.h>  
void main(){
    int n ,i,count=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    if(n<=1)
    printf("%d is not a prime number",n);
    else{
        for(i=2;i<n/2;i++){//n/2 isliye liya hai kyuki kisi bhi number ka factor uske half se zyada nahi hota, isliye hum n/2 tak hi loop chalate hai, aur i=2 se start karte hai kyuki 1 har number ka factor hota hai aur prime number ke definition ke hisab se 1 ko consider nahi kiya jata`
            //hum root(n) bhi le sakte hai, kyuki kisi bhi number ka factor uske square root se zyada nahi hota, lekin n/2 lena bhi sahi hai, aur isse code thoda simple ho jata hai root n se complexticity kaam ho jati kyuki woh number kaam kar dete hai 
            if(n%i==0){ //yeh condition check karta hai ki n ko i se divide karne par remainder 0 aata hai ya nahi, agar aata hai to iska matlab n prime number nahi hai
                count++;
                break;
            }
        }
    }
    if (count==0)    printf("%d is a prime number",n);
    else    printf("%d is not a prime number",n);
}

