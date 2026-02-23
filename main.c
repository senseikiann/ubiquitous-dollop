int main(void)
{
    while(1)
    {
        for(volatile int i=0;i<100000;i++);
    }
}
