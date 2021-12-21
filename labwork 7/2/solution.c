#include <fcntl.h>
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
	int fds[2];
	char digit[2]; 
	int i, res = 0;
	fd_set inset, watchset = { {0} };
	
	fds[0] = open("in1", O_RDONLY|O_NDELAY); 
	fds[1] = open("in2", O_RDONLY|O_NDELAY);
	
	*watchset.__fds_bits |= (1 << fds[0]) | (1 << fds[1]);

	while (*watchset.__fds_bits) {
		inset = watchset;
		select(fds[1] + 1, &inset, NULL, NULL, NULL);

		for (i = 0; i != 2; ++i) {
			if (*inset.__fds_bits & (1 << fds[i])) {
				if (read(fds[i], digit, 2)) {
					res += (*digit - '0');
				} else {
					close(fds[i]);
					*watchset.__fds_bits &= ~(1 << fds[i]);
				}
			}
		}
	}
		return printf("%d\n", res) & 0;
}
