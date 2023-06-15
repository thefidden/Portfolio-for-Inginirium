document.addEventListener('DOMContentLoaded', () => {
    let urlParams = new URLSearchParams(window.location.search)

    if (urlParams.get('action'))
        document.getElementById('action').value = urlParams.get('action')
})

let select_onchange = function () {
    let action = document.getElementById('action').value
    let first = document.getElementById('first').value
    let second

    if(document.getElementById('second'))
        second = document.getElementById('second').value
    else
        second = ''

    let url = new URL(window.location.href);
    let params = url.searchParams;

    params.set('first', `${first}`)
    params.set('second', `${second}`)
    params.set('action', `${action}`)

    location.replace(url.toString());
}
