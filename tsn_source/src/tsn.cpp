#include "include/Controller.h"

int main(int argc, char *argv[]) {
    Node node;
    View view;
    Controller controller(&view, &node);
    controller.cli();

    return 0;
}
