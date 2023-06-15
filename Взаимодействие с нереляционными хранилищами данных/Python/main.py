from Database import Database


def main(*args, **kwargs) -> int:
    database = Database('../JSON/countries.json')

    # Чтение данных
    database.get_data()

    # Виузализация данных
    print(f'Чтение всех данных: {database.__str__()}')

    # Поиск данных
    print(f"""Выборка данных: {database.search_by_fields_and_values(
        criteria = {
            'name': 'Russia'
        }
    )}""")

    # Добавление данных
    database.add_data({
        'name': 'United States of America',
        'population': 331_900_000,
        'area': 9_519_431
    })

    # Обновление данных
    database.update_objects(
        old_values = {
            'name': 'Russia'
        },
        new_values = {
            'area': 17_100_000,
            'population': 143_400_000
        }
    )

    # Поиск данных
    print(f"""Выборка данных: {database.search_by_fields_and_values(
        criteria = {
            'name': 'Russia'
        }
    )}""")

    # Поиск данных
    print(f"""Выборка данных: {database.search_by_fields_and_values(
        criteria = {
            'area': 9_519_431
        }
    )}""")

    # Сохранение данных
    database.save_data(path = '../JSON/countries_copy.json')

    return 0


if __name__ == '__main__':
    main()
