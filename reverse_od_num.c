/reverse a number in C
#include <stdio.h>
int main(){
    int n,rev=0,rem;
    printf("Enter a number: ");
    scanf("%d",&n);
    while(n!=0){
        rem =n%10;//yeh line number ke last digit ko rem variable me store karne ke liye hai, n%10 se hume number ka last digit milta hai, aur usse hum rev variable me store karte hai}
        rev=rev*10+rem;// rev variable ko update karne ke liye hai, rev*10 se hum rev variable ke digits ko left shift karte hai, aur rem variable me jo last digit hai usse add karte hai, isse rev variable me number ka reverse ban jata hai
        n=n/10;// number ke last digit ko remove karne ke liye hai, n/10 decimal part ko hata deta jaise 123/10=12.3 to n ki value 12 ho jati hai, isse hum next iteration me number ke next last digit ko rem variable me store kar sakte hai
}
printf("Reversed number: %d",rev);

return 0;
}
