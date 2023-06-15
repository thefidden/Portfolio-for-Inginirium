<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Calendar</title>
</head>
<body>
<?php
    $day_of_current_month = date("j"); // Номер текущего дня в текущем месяце без ведущего '0' (1 - 31)
    $current_month_number = date("n"); // Номер текущего месяца (1 - 12)
    $year = date("Y"); // Текущий год в формате YYYY

    $days_array = array("", "Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс");
    $month_names_ru = array("Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь");
    $month_names_en = array("January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December");

    $months = array();
    // Создание ассоциативного массива, в котором ключи - номер месяца (1 - 12), а значения - ассоциативный массив, содержащий информацию о месяце
    for ($index = 1; $index <= 12; $index++)
        $months[strval($index)] = array(
            'name_ru' => $month_names_ru[$index - 1],
            'name_en' => $month_names_en[$index - 1],
            'number' => $index, // Номер месяца (1 - 12)
            'month_days' => date('t', strtotime("$year-$index-01")), // Кол-во дней в месяце
            'number_of_first_day_of_month' => date("w", mktime(0, 0, 0, $index, 1, $year)), // Номер в неделе первого дня в текущем месяце (0 - 6)
            'weeks' => round(date('t', strtotime("$year-$index-01")) / 7, 0) // Кол-во недель в месяце
        );

    foreach ($months as $name => $month) {
        echo "<font color=red><b>" . $month['name_ru'] . "($year)</b></font>";
        echo "<table width='200' border='0' cellspacing='0' cellpadding='5'>";

        echo "<tr>";
        for ($day = 1, $color = '#000000'; $day <= 7; $day++, $color = '#000000') {
            if ($day > 5)
                $color = '#E4723A';
            echo "\t\t<td><font color=$color>" . $days_array[$day] . "</font></td>\n";
        }
        echo "</tr>";

        echo "<tr>";

        $day_of_week = 1;
        while ($day_of_week < $month['number_of_first_day_of_month']) {
            echo "<td>&nbsp;</td>";
            $day_of_week++;
        }

        for ($day = 1; $day <= $month['month_days']; $day++) {
            if ($day == $day_of_current_month && $month['number'] == $current_month_number) {
                echo "\t\t<td bgcolor='#FF8040' align='center'><b>$day</b></td>\n";
            } else {
                echo "\t\t<td align='center'>$day</td>\n";
            }
            if (round($day_of_week / 7) - $day_of_week / 7 == 0) {
                echo "\t</tr>\n\t<tr>\n";
            }
            $day_of_week++;
        }

        echo "</tr></table><br><br>";
    }
?>
</body>
</html>
