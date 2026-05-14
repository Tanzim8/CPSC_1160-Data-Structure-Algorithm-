//I will write a recursive function to calculate fibonacci numbers!
int fibb(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }
    return fibb(n-1)+fibb(n-2);
}