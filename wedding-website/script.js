// Countdown Timer
const weddingDate = new Date("February 14, 2026 00:00:00").getTime();

function updateCountdown() {
    const now = new Date().getTime();
    const distance = weddingDate - now;

    if (distance < 0) {
        document.querySelector('.countdown').innerHTML = "<p>It's Happening!</p>";
        return;
    }

    const days = Math.floor(distance / (1000 * 60 * 60 * 24));
    const hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
    const minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
    const seconds = Math.floor((distance % (1000 * 60)) / 1000);

    document.getElementById("days").innerText = String(days).padStart(2, '0');
    document.getElementById("hours").innerText = String(hours).padStart(2, '0');
    document.getElementById("minutes").innerText = String(minutes).padStart(2, '0');
    document.getElementById("seconds").innerText = String(seconds).padStart(2, '0');
}

setInterval(updateCountdown, 1000);

// Confetti Effect
const canvas = document.getElementById('confetti-canvas');
const ctx = canvas.getContext('2d');
canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

let confetti = [];
const colors = ['#FFD1DC', '#D4AF37', '#FF69B4', '#FFFDD0'];

function createConfetti() {
    for (let i = 0; i < 100; i++) {
        confetti.push({
            x: Math.random() * canvas.width,
            y: Math.random() * canvas.height - canvas.height,
            color: colors[Math.floor(Math.random() * colors.length)],
            size: Math.random() * 5 + 5,
            speedY: Math.random() * 3 + 2,
            speedX: Math.random() * 2 - 1
        });
    }
}

function drawConfetti() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    confetti.forEach((piece, index) => {
        ctx.fillStyle = piece.color;
        ctx.beginPath();
        ctx.arc(piece.x, piece.y, piece.size, 0, Math.PI * 2);
        ctx.fill();

        piece.y += piece.speedY;
        piece.x += piece.speedX;

        if (piece.y > canvas.height) {
            confetti.splice(index, 1);
        }
    });

    if (confetti.length > 0) {
        requestAnimationFrame(drawConfetti);
    }
}

document.getElementById('save-date-btn').addEventListener('click', () => {
    createConfetti();
    drawConfetti();
    alert("Date Saved! ❤️ Can't wait on Feb 14, 2026!");
});

// Love Meter
document.getElementById('love-meter-btn').addEventListener('click', () => {
    const vibes = [
        "100% Soulmates! ❤️",
        "Match made in Heaven! ☁️",
        "Infinite Love! ♾️",
        "Better than Bollywood! 🎬",
        "Pure Magic! ✨"
    ];
    const randomVibe = vibes[Math.floor(Math.random() * vibes.length)];
    document.getElementById('meter-result').innerText = randomVibe;
    createConfetti();
    drawConfetti();
});

// Guestbook (Simple Local Demo)
document.getElementById('submit-msg').addEventListener('click', () => {
    const msgInput = document.getElementById('guest-msg');
    const msg = msgInput.value.trim();
    if (msg) {
        const list = document.getElementById('messages-list');
        const card = document.createElement('div');
        card.className = 'msg-card';
        card.innerText = msg + " - Guest";
        list.prepend(card);
        msgInput.value = '';
    } else {
        alert("Please write a sweet message first!");
    }
});

// Resize Canvas
window.addEventListener('resize', () => {
    canvas.width = window.innerWidth;
    canvas.height = window.innerHeight;
});
