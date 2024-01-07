#include <X11/X.h>
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>




int main(int argc, char *argv[]) {
  unsigned int with = atoi(argv[0]);
  unsigned int hith = atoi(argv[1]);

  XEvent evint;
  Display* display = XOpenDisplay(NULL);


  Window root = XCreateSimpleWindow(display, DefaultRootWindow(display), 0, 0, with, hith, 1, BlackPixel(display, 0), WhitePixel(display, 0));
  system("kitty tmux");
  XMapWindow(display, root);
  XSelectInput(display, root, ExposureMask);
  for (;;) {
    XNextEvent(display, &evint);
    if (evint.type == Expose){

    }
  }

  XClearWindow(display, root);
  XCloseDisplay(display);
  return 0;
}
