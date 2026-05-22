function goToDashboard() {

    window.location.href =
        "dashboard.html";
}

function updateClock() {

    const now = new Date();

    const time =
        now.toLocaleTimeString();

    document.getElementById("clock")
        .innerHTML = time;
}

setInterval(updateClock, 1000);

updateClock();

function showTicket() {

    document.getElementById(
        "ticketPopup"
    ).style.display = "flex";
}

function closeTicket() {

    document.getElementById(
        "ticketPopup"
    ).style.display = "none";
}