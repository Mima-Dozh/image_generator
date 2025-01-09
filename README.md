# image_generator

# Используемые инструменты

Для установки пакетов используется [vcpkg](https://vcpkg.io/en/)

Для коректной работы установите перемную окружения

VCPKG_ROOT=<путь до vcpkg>

# Сборка

Сборка происходит через cmake

Сборка осуществляется в фаиле build_my_project.sh

Пример запуска
```shell
bash build_my_project.sh

```

Запуск проекта осуществляется в фаиле run.sh

Он принимает на вход пути до фаилов в которых содержится описание точек

Пример запуска
```shell
bash run.sh  file1.bin file2.txt file3.json file4.bin

```
