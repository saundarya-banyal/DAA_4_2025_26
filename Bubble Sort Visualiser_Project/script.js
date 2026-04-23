let array = [];
const container = document.getElementById("array-container");

const COLORS = {
  DEFAULT: "turquoise",
  COMPARE: "red",
  SWAP: "yellow",
  SORTED: "green"
};

function generateArray() {
  const size = parseInt(document.getElementById("sizeInput").value);

  if (isNaN(size) || size < 1 || size > 50) {
    alert("Enter a valid size between 1 and 50");
    return;
  }

  container.innerHTML = "";
  array = [];

  const width = Math.max(600 / size, 5); 
  for (let i = 0; i < size; i++) {
    let value = Math.floor(Math.random() * 50) + 1;
    array.push(value);

    const bar = document.createElement("div");
    bar.classList.add("bar");

    bar.style.height = `${value * 6}px`;
    bar.style.width = `${width}px`;

    container.appendChild(bar);
  }
}

function startSort() {
  if (array.length === 0) {
    alert("Generate array first!");
    return;
  }

  const animations = bubbleSort(array.slice());
  animate(animations);
}

function bubbleSort(arr) {
  let animations = [];
  let n = arr.length;

  for (let i = 0; i < n - 1; i++) {
    let swapped = false;

    for (let j = 0; j < n - i - 1; j++) {

      animations.push({ type: "compare", i: j, j: j + 1 });

      if (arr[j] > arr[j + 1]) {
        swapped = true;

        animations.push({
          type: "swap",
          i: j,
          j: j + 1,
          val1: arr[j + 1],
          val2: arr[j]
        });

        let temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }

    animations.push({ type: "sorted", index: n - i - 1 });
    if (!swapped) break;
  }
  for (let i = 0; i < n; i++) {
    animations.push({ type: "sorted", index: i });
  }

  return animations;
}

function animate(animations) {
  const bars = document.getElementsByClassName("bar");

  animations.forEach((step, i) => {
    setTimeout(() => {

      if (step.type === "compare") {
        bars[step.i].style.backgroundColor = COLORS.COMPARE;
        bars[step.j].style.backgroundColor = COLORS.COMPARE;

        setTimeout(() => {
          if (bars[step.i].style.backgroundColor !== COLORS.SORTED)
            bars[step.i].style.backgroundColor = COLORS.DEFAULT;

          if (bars[step.j].style.backgroundColor !== COLORS.SORTED)
            bars[step.j].style.backgroundColor = COLORS.DEFAULT;
        }, 30);
      }

      if (step.type === "swap") {
        bars[step.i].style.height = `${step.val1 * 6}px`;
        bars[step.j].style.height = `${step.val2 * 6}px`;

        bars[step.i].style.backgroundColor = COLORS.SWAP;
        bars[step.j].style.backgroundColor = COLORS.SWAP;

        setTimeout(() => {
          if (bars[step.i].style.backgroundColor !== COLORS.SORTED)
            bars[step.i].style.backgroundColor = COLORS.DEFAULT;

          if (bars[step.j].style.backgroundColor !== COLORS.SORTED)
            bars[step.j].style.backgroundColor = COLORS.DEFAULT;
        }, 30);
      }

      if (step.type === "sorted") {
        bars[step.index].style.backgroundColor = COLORS.SORTED;
      }

    }, i * 25); 
  });
}