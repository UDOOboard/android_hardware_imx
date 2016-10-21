#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <linux/types.h>
#include <linux/videodev2.h>

#define VIDIOC_S_CTRL           _IOWR('V', 28, struct v4l2_control)

int main(void) {
	char v4l_device[32] = "/dev/video0";
	int cap_fd;

	if ((cap_fd = open(v4l_device, O_RDWR, 0)) < 0) {
		printf("Unable to open %s\n", v4l_device);
		return -1;
	}

	struct v4l2_control control;

	memset(&control, 0, sizeof (control));
	control.id = V4L2_CID_AUTO_FOCUS_START;
	control.value = 0;

	if (-1 == ioctl(cap_fd, VIDIOC_S_CTRL, &control)) perror("VIDIOC_S_CTRL");

	return 0;
}


