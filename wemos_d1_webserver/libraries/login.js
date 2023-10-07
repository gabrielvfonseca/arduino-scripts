const loginForm = document.getElementById("login");
const loginButton = document.getElementById("login");
const loginErrorMsg = document.getElementById("login_error_msg");
const dashboard = document.getElementById("dashboard");
const username = document.getElementById("user");
const password = document.getElementById("pass");

// Get login access data
loginAlert();

loginButton.addEventListener("click", function() {
    if (username === "arduino" && password === "1234") {
        loginAlert();
        location.reload();
    }
})

function loginAlert() {
    if (localStorage.getItem('login', 'Tom') != undefined) {
        console.log("Authentication: True");
        document.getElementById("dashboard").style.display = "inline-block";
    }
    else {
        localStorage.setItem('login', '1234');
        console.log("Authentication: False");
    }
}