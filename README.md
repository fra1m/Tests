# Tests

## Шаг 1: Клонирование репозитория

Сначала клонируйте репозиторий на вашу локальную машину, используя Git:

```bash
git clone git@github.com:fra1m/Tests.git
```

## Шаг 2: Перейдите в директорию проекта

```bash
cd <name>
```

## Шаг 3: Запуск

Для запуска запустите скрипт: `run_test.sh`, который скопилирует и запустить файл `test_zd.cpp`. После у вас появится исполняемый файл `test_zd` в этой же дириктории

Если при компиляции произошли проблемы, то попробуйте в терминале:
```bash
g++ -o test_zd test_zd.cpp
```