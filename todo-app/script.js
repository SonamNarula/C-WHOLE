// NebulaDo - Core Systems initialized
const taskInput = document.getElementById('task-input');
const addBtn = document.getElementById('add-btn');
const taskList = document.getElementById('task-list');
const xpFill = document.getElementById('xp-bar-fill');
const xpText = document.getElementById('xp-text');
const levelNumber = document.getElementById('level-number');
const rankName = document.getElementById('rank-name');

// State
let tasks = JSON.parse(localStorage.getItem('nebulaTasks')) || [];
let userStats = JSON.parse(localStorage.getItem('nebulaStats')) || {
    xp: 0,
    level: 1,
    rank: 'Cadet'
};

// Rank System
const ranks = [
    { level: 1, name: 'Cadet', xpNeeded: 100 },
    { level: 2, name: 'Explorer', xpNeeded: 250 },
    { level: 3, name: 'Star Walker', xpNeeded: 500 },
    { level: 4, name: 'Void Hunter', xpNeeded: 1000 },
    { level: 5, name: 'Cosmic Lord', xpNeeded: 2000 }
];

// Init
document.addEventListener('DOMContentLoaded', () => {
    updateStatsUI();
    renderTasks();
});

// Event Listeners
addBtn.addEventListener('click', addTask);
taskInput.addEventListener('keydown', (e) => {
    if (e.key === 'Enter') addTask();
});

function addTask() {
    const text = taskInput.value.trim();
    if (!text) return;

    const newTask = {
        id: Date.now(),
        text: text,
        completed: false,
        createdAt: new Date()
    };

    tasks.unshift(newTask);
    saveData();

    // Animate insertion
    renderTasks();
    const firstTask = taskList.firstElementChild;
    if (firstTask) firstTask.classList.add('task-enter');

    taskInput.value = '';
}

function toggleTask(id) {
    const taskIndex = tasks.findIndex(t => t.id === id);
    if (taskIndex === -1) return;

    const task = tasks[taskIndex];

    // Toggle state
    task.completed = !task.completed;

    // If completing, add XP
    if (task.completed) {
        addXP(50); // 50 XP per task
        // Move to bottom? Or simplify visuals. Let's keep position but style it.
    } else {
        // Penalty for un-checking? Nah, just revert.
        removeXP(50);
    }

    saveData();
    renderTasks();
}

function deleteTask(id, element) {
    element.classList.add('fade-out');

    setTimeout(() => {
        tasks = tasks.filter(t => t.id !== id);
        saveData();
        renderTasks();
    }, 400); // Wait for animation
}

function addXP(amount) {
    userStats.xp += amount;
    checkLevelUp();
    updateStatsUI();
    saveData();
}

function removeXP(amount) {
    userStats.xp = Math.max(0, userStats.xp - amount);
    // Logic to level down? Optional. Let's keep level for now.
    updateStatsUI();
    saveData();
}

function checkLevelUp() {
    const currentRank = ranks.find(r => r.level === userStats.level) || ranks[ranks.length - 1];

    // Look for next rank
    const nextRank = ranks.find(r => r.level === userStats.level + 1);

    if (nextRank && userStats.xp >= currentRank.xpNeeded) {
        levelUp(nextRank);
    }
}

function levelUp(newRank) {
    userStats.level = newRank.level;
    userStats.rank = newRank.name;
    // userStats.xp = 0; // Reset XP? Or keep accumulating?
    // Let's keep accumulating for global progress, but bar handles progress to next level

    alert(`SYSTEM ALERT: PROMOTION GRANTED\nNew Rank: ${newRank.name}`);
}

function updateStatsUI() {
    const currentRank = ranks.find(r => r.level === userStats.level) || ranks[ranks.length - 1];
    const nextRank = ranks.find(r => r.level === userStats.level + 1);

    levelNumber.textContent = userStats.level;
    rankName.textContent = userStats.rank;

    if (nextRank) {
        // Calculate progress within current level
        // Previous level cap
        const prevLevelCap = ranks.find(r => r.level === userStats.level - 1)?.xpNeeded || 0;
        const levelSpan = currentRank.xpNeeded - prevLevelCap;

        // This logic is a bit tricky with "xpNeeded" being cumulative.
        // Let's simplify: Bar shows progress towards NEXT rank.

        const currentLevelBase = userStats.level === 1 ? 0 : ranks.find(r => r.level === userStats.level - 1).xpNeeded;
        const target = currentRank.xpNeeded; // This is actually "XP needed to finish this level"

        // Let's fix logic:
        // Rank 1 needs 100 total XP to reach Rank 2.
        // So valid range is [0, 100].

        // Correct logic:
        const nextLevelThreshold = currentRank.xpNeeded; // e.g. 100 for level 1 to become 2?? No, let's say "xpNeeded" is to COMPLETE the level.

        // Let's assume cumulative XP.
        // XP: 50. Level 1 (Cadet). Target: 100.
        // XP: 150. Level 2 (Explorer). Target: 250.

        let previousThreshold = 0;
        if (userStats.level > 1) {
            previousThreshold = ranks.find(r => r.level === userStats.level - 1)?.xpNeeded || 0;
        }

        const nextThreshold = currentRank.xpNeeded;
        const currentProgress = userStats.xp - previousThreshold;
        const levelRange = nextThreshold - previousThreshold;

        const percentage = Math.min(100, Math.max(0, (currentProgress / levelRange) * 100));

        xpFill.style.width = `${percentage}%`;
        xpText.textContent = `${userStats.xp} / ${nextThreshold} XP`;
    } else {
        // Max level
        xpFill.style.width = '100%';
        xpText.textContent = 'MAX LEVEL';
    }
}

function renderTasks() {
    taskList.innerHTML = '';

    tasks.forEach(task => {
        const li = document.createElement('li');
        li.className = `task-item ${task.completed ? 'completed' : ''}`;
        li.dataset.id = task.id;

        li.innerHTML = `
            <span class="task-text">${task.text}</span>
            <div class="task-actions">
                <button class="delete-btn" onclick="event.stopPropagation(); deleteTask(${task.id}, this.closest('.task-item'))">✕</button>
            </div>
        `;

        // Click to toggle
        li.addEventListener('click', () => toggleTask(task.id));

        taskList.appendChild(li);
    });
}

function saveData() {
    localStorage.setItem('nebulaTasks', JSON.stringify(tasks));
    localStorage.setItem('nebulaStats', JSON.stringify(userStats));
}
