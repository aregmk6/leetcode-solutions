int removeElement(int *nums, int numsSize, int val) {
    int *insert_at = nums;
    int *cur_num = nums;
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (*cur_num != val) {
            *insert_at = *cur_num;
            insert_at++;
            count++;
        }
        cur_num++;
    }

    return count;
}
