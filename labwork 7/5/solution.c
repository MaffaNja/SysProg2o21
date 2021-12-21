#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>

int main(int argc, char *argv[]) {
	// existed shared memory
	key_t key_shm1 = atoi(argv[1]);
	key_t key_shm2 = atoi(argv[2]);
	int shmid1 = shmget(key_shm1, 1000, 0600  | IPC_CREAT);
	int shmid2 = shmget(key_shm2, 1000, 0600  | IPC_CREAT);
	int* shm1 = shmat(shmid1, NULL, 0);
	int* shm2 = shmat(shmid2, NULL, 0);

	// created shared memory
	key_t my_key_shm = key_shm1 + key_shm2;
	int my_shmid = shmget(my_key_shm, 1000, 0666  | IPC_CREAT);
	int* my_shm = shmat(my_shmid, NULL, 0);

	int i = 0;
	for (; i < 100; ++i) {
		my_shm[i] = shm1[i] + shm2[i];
	}

	printf("%d\n", my_key_shm);

	return 0;
}