<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <script src='JS/index.js'></script>
    <title>Calculator</title>
</head>
<body>
<?php
    function calc($first, $second, $action) {
        if(!$action)
            return 0;

        if(!$first)
            $first = 0;

        if(!$second)
            $second = 0;

        $actions = array(
            'add' => function ($a, $b) {
                return $a + $b;
            },
            'subtract' => function ($a, $b) {
                return $a - $b;
            },
            'multiply' => function ($a, $b) {
                return $a * $b;
            },
            'divide' => function ($a, $b) {
                if (!$b)
                    exit("Второе число не введено или равно нулю<br><a href=calculator.php>Назад</a>");
                return $a / $b;
            },
            'power' => function ($a, $b) {
                return $a ** $b;
            },
            'percent' => function ($a, $b) {
                return $a * $b / 100;
            },
            'sqrt' => function ($a, $b) {
                return $a ** 0.5;
            },
            'sinus' => function ($a, $b) {
                return sin(deg2rad($a));
            },
            'cosine' => function ($a, $b) {
                return cos(deg2rad($a));
            },
            'tangent' => function ($a, $b) {
                return tan(deg2rad($a));
            },
            'cotangent' => function ($a, $b) {
                return 1 / tan(deg2rad($a));
            }
        );

        return $actions[$action]($first, $second);
    }

    function show() { ?>
        <form method="get" action="calculator.php" id="form">
        <table border="1" cellspacing="2" cellpadding="2">
            <tr>
                <td>
                    Первое число:
                </td>
                <td>
                    <?php
                        $value = $_GET['first'];
                        echo "<input size='14' type='text' name='first' id = 'first' value='$value'>";
                    ?>

                </td>
            </tr>
            <tr><?php
                    if (!in_array($_GET['action'], array('sqrt', 'sinus', 'cosine', 'tangent', 'cotangent'))) { ?>
            <tr>
                <td>
                    Второе число:
                </td>
                <td>
                    <?php
                        $value = $_GET['second'];
                        echo "<input size='14' type='text' name='second' id = 'second' value='$value'>";
                    ?>
                </td>
            </tr>
            <?php } ?>

            <tr>
                <td>
                    <select size="1" name="action" id="action" onchange="select_onchange()">
                        <option value="add" selected = 'selected'>Сложить</option>
                        <option value="subtract">Вычесть</option>
                        <option value="multiply">Умножить</option>
                        <option value="divide">Разделить</option>
                        <option value="power">Возвести в степень</option>
                        <option value="percent">Вычислить процент</option>
                        <option value="sqrt">Квадратный корень</option>
                        <option value="sinus">Синус</option>
                        <option value="cosine">Косинус</option>
                        <option value="tangent">Тангенс</option>
                        <option value="cotangent">Котангенс</option>
                    </select>
                </td>
                <td>
                    <input type="submit" value="Выполнить">
                </td>
            </tr>
            <tr>
                <td>
                    Результат:
                </td>
                <td>
                    <div align="center">
                        <?php
                            echo calc($_GET['first'], $_GET['second'], $_GET['action']);
                        ?>
                    </div>
                </td>
            </tr>
        </table>
        </form><?php
    }

    show();
?>
</body>
</html>
