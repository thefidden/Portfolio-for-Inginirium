import pymysql
from JSON_Database import JSON_Database


class MySQL_Database:
    def __init__(self, host: str, port: int, user: str, password: str, database: str):
        self.host = host
        self.port = port
        self.user = user
        self.password = password
        self.database = database

    # Удаление таблицы
    def delete_table(self, table_name: str) -> 'MySQL_Database':
        try:
            connection = pymysql.connect(
                host = self.host,
                port = self.port,
                user = self.user,
                password = self.password,
                database = self.database,
                cursorclass = pymysql.cursors.DictCursor
            )

            try:
                with connection.cursor() as cursor:
                    cursor.execute(f"""
                        DROP TABLE IF EXISTS {table_name}
                    """)

            finally:
                connection.commit()
                connection.close()

        except Exception:
            print(f'Operation failed: {Exception}')

        return self

    # Дублирование таблицы
    def duplicate_table(self, original_table_name: str, copied_table_name: str) -> 'MySQL_Database':
        try:
            connection = pymysql.connect(
                host = self.host,
                port = self.port,
                user = self.user,
                password = self.password,
                database = self.database,
                cursorclass = pymysql.cursors.DictCursor
            )

            try:
                with connection.cursor() as cursor:
                    cursor.execute(f"""
                        CREATE TABLE IF NOT EXISTS {copied_table_name}
                        SELECT * FROM {original_table_name}
                    """)

            finally:
                connection.commit()
                connection.close()

        except Exception:
            print(f'Operation failed: {Exception}')

        return self

    # Добавление данных
    def add_objects(self, table_name: str, *objects: dict) -> 'MySQL_Database':
        try:
            connection = pymysql.connect(
                host = self.host,
                port = self.port,
                user = self.user,
                password = self.password,
                database = self.database,
                cursorclass = pymysql.cursors.DictCursor
            )

            try:
                with connection.cursor() as cursor:
                    for object in objects:
                        cursor.execute(f"""
                            INSERT INTO {table_name} (name, population, area) values (%s, %s, %s)
                        """, [object['name'], object['population'], object['area']])

            finally:
                connection.commit()
                connection.close()

        except Exception:
            print(f'Operation failed: {Exception}')

        return self

    # Чтение данных
    def read_all(self, table_name: str) -> list:
        result = []
        try:
            connection = pymysql.connect(
                host = self.host,
                port = self.port,
                user = self.user,
                password = self.password,
                database = self.database,
                cursorclass = pymysql.cursors.DictCursor
            )

            try:
                with connection.cursor() as cursor:
                    cursor.execute(f"""
                        SELECT * FROM {table_name}
                    """)
                    result = cursor.fetchall()

            finally:
                connection.commit()
                connection.close()

        except Exception:
            print(f'Operation failed: {Exception}')

        return list(result)

    # Поиск данных
    def search_by_fields_and_values(self, table_name: str, criteria: dict) -> dict:
        result = []
        try:
            connection = pymysql.connect(
                host = self.host,
                port = self.port,
                user = self.user,
                password = self.password,
                database = self.database,
                cursorclass = pymysql.cursors.DictCursor
            )

            try:
                with connection.cursor() as cursor:
                    cursor.execute(f"""
                                SELECT * FROM {table_name}
                                WHERE {' AND '.join(f"{column} = '{value}'" for column, value in criteria.items())}
                            """)
                    result = cursor.fetchall()

            finally:
                connection.commit()
                connection.close()

        except Exception:
            print(f'Operation failed: {Exception}')

        return list(result)

    # Обновление данных
    def update_objects(self, table_name: str, old_values: dict, new_values: dict) -> 'MySQL_Database':

        connection = pymysql.connect(
            host = self.host,
            port = self.port,
            user = self.user,
            password = self.password,
            database = self.database,
            cursorclass = pymysql.cursors.DictCursor
        )

        try:
            with connection.cursor() as cursor:
                cursor.execute(f"""
                        UPDATE {table_name}
                        SET {', '.join(f'{column} = {value}' for column, value in new_values.items())}
                        WHERE {' AND '.join(f"{column} = '{value}'" for column, value in old_values.items())}
                    """)

        finally:
            connection.commit()
            connection.close()

        return self
