// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
//
// #define ROOM_NAME_SIZE 100
// #define TEMPERATURE_ROOM_ARRAYLIST_SIZE 50
//
// typedef struct temperature_room {
//     char temperature[ROOM_NAME_SIZE];
//     char room[ROOM_NAME_SIZE];
// } TemperatureRoomArrayList;
//
// int compare_rooms1(const void *a, const void *b) {
//     return strcmp(((TemperatureRoomArrayList *)a)->room, ((TemperatureRoomArrayList *)b)->room);
// }
//
// // 显示菜单并去重房间名称
// void show_menu1(TemperatureRoomArrayList *temperature_room_arrays, int room_count) {
//     qsort(temperature_room_arrays, room_count, sizeof(TemperatureRoomArrayList), compare_rooms);
//
//     printf("Available rooms:\n");
//
//     // 打印去重后的房间名称
//     for (int i = 0; i < room_count; i++) {
//         if (i == 0 || strcmp(temperature_room_arrays[i].room, temperature_room_arrays[i - 1].room) != 0) {
//             printf("%d. %s\n", i + 1, temperature_room_arrays[i].room);
//         }
//     }
// }
//
// int main() {
//     // 示例数据，注意这里的实际房间数量
//     TemperatureRoomArrayList temperature_room_arrays[TEMPERATURE_ROOM_ARRAYLIST_SIZE] = {
//         {"22.5", "Kitchen"},
//         {"18.7", "Living Room"},
//         {"24.2", "Bedroom"},
//         {"20.1", "Kitchen"},
//         {"12.3", "Living Room"},
//         {"23.8", "Bedroom"},
//         {"16.9", "Kitchen"},
//         {"19.4", "Living Room"},
//         {"13.7", "Bedroom"},
//         {"21.8", "Kitchen"},
//         {"11.5", "Living Room"},
//         {"24.9", "Bedroom"}
//     };
//
//     // 房间数据的实际数量
//     int room_count = 12;
//
//     // 调用显示菜单的函数
//     show_menu1(temperature_room_arrays, room_count);
//
//     return 0;
// }
