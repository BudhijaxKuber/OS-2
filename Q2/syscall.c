SYSCALL_DEFINE4(kernel_2d_memcpy, float**, src, float**, dest, int row, int, col){
    int size = sizeof(float)*(row*col);
    float temp[20][20];
    __copy_from_user(temp,src,size);
    __copy_to_user(dest,temp,size);
    return 0;
}