from JSON_Database import JSON_Database
from MySQL_Database import MySQL_Database
from config import host, user, password


def main(*args, **kwargs) -> int:
    database = MySQL_Database(
        host = host,
        port = 3306,
        user = user,
        password = password,
        database = 'belyaev'
    )

    print(f"Чтение всех данных: {database.read_all('countries')}")

    print(f"""Выборка данных: {database.search_by_fields_and_values(
        table_name = 'countries_1',
        criteria = {
            'name': 'Russia'
        }
    )}""")

    # Обновление данных
    database.update_objects(
        table_name = 'countries_1',
        old_values = {
            'name': 'Russia'
        },
        new_values = {
            'area': 17_100_000,
            'population': 143_400_000
        }
    )

    # Добавление данных
    database.add_objects(
        'countries_1',
        {
            'name': 'United States of America',
            'population': 331_900_000,
            'area': 9_519_431
        }
    )

    print(f"""Выборка данных: {database.search_by_fields_and_values(
        table_name = 'countries_1',
        criteria = {
            'name': 'Russia'
        }
    )}""")

    print(f"""Выборка данных: {database.search_by_fields_and_values(
        table_name = 'countries_1',
        criteria = {
            'area': 9_519_431
        }
    )}""")

    return 0


if __name__ == '__main__':
    main()
