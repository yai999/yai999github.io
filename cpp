<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta name="google-adsense-account" content="ca-pub-1142019306541908">
  <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=0" />
  <meta property="og:title" content="iton5 LAE TH">
  <meta property="og:type" content="website">
  <meta property="og:description" content="LIFF Dynamic link change Rich Menu x Dropdown Sheet">
  <meta property="og:url" content="https://www.facebook.com/stickerlinebyiton5">
  <meta property="og:site_name" content="LIFF Dynamic link change Rich Menu x Dropdown Sheet">
  <meta property="og:image" content="https://lh3.googleusercontent.com/d/1FldOWgeB9OqhFP3CLKT3S-rjTyFCufnk">

  <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.7.1/jquery.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
  <link rel="stylesheet" href="https://bit.ly/fontiton5" type="text/css" charset="utf-8" />
  <style type="text/css">
    body {
      font-family: 'line_seed_sans_th';
    }

    .ball {
      position: absolute;
      border-radius: 100%;
      opacity: 0.7;
    }
  </style>
  <script src="https://cdn.tailwindcss.com"></script>
  <title id="title">LIFF Share Flex for Rich Menu</title>
</head>

<body>

  <div class="mx-auto max-w-7xl px-4 sm:px-6 lg:px-8 pt-20 pb-16 text-center lg:pt-32">
    <p class="mx-auto -mt-4 max-w-2xl text-lg tracking-tight text-slate-700 sm:mt-6">ยินดีต้อนรับ

    </p>

    <h1 class="mx-auto max-w-4xl font-display text-5xl font-medium tracking-tight text-slate-900 sm:text-7xl">
      <span class="inline-block">คุณ
        <span class="relative whitespace-nowrap text-blue-600">
          <svg aria-hidden="False" viewBox="0 0 418 42"
            class="absolute top-2/3 left-0 h-[0.58em] w-full fill-blue-300/70" preserveAspectRatio="none">
            <path
              d="M203.371.916c-26.013-2.078-76.686 1.963-124.73 9.946L67.3 12.749C35.421 18.062 18.2 21.766 6.004 25.934 1.244 27.561.828 27.778.874 28.61c.07 1.214.828 1.121 9.595-1.176 9.072-2.377 17.15-3.92 39.246-7.496C123.565 7.986 157.869 4.492 195.942 5.046c7.461.108 19.25 1.696 19.17 2.582-.107 1.183-7.874 4.31-25.75 10.366-21.992 7.45-35.43 12.534-36.701 13.884-2.173 2.308-.202 4.407 4.442 4.734 2.654.187 3.263.157 15.593-.78 35.401-2.686 57.944-3.488 88.365-3.143 46.327.526 75.721 2.23 130.788 7.584 19.787 1.924 20.814 1.98 24.557 1.332l.066-.011c1.201-.203 1.53-1.825.399-2.335-2.911-1.31-4.893-1.604-22.048-3.261-57.509-5.556-87.871-7.36-132.059-7.842-23.239-.254-33.617-.116-50.627.674-11.629.54-42.371 2.494-46.696 2.967-2.359.259 8.133-3.625 26.504-9.81 23.239-7.825 27.934-10.149 28.304-14.005.417-4.348-3.529-6-16.878-7.066Z">
            </path>
          </svg>
          <span class="relative" id="displayname">DisplayName</span></span>
      </span>

    </h1>
  </div>

  <div id="loading-overlay"
    class="fixed inset-0 bg-gray-500 bg-opacity-75 z-50 flex items-center justify-center hidden">
    <img
      src="https://media4.giphy.com/media/v1.Y2lkPTc5MGI3NjExOHVpNjNleDQ2MTI0aTZwY3NzcmJvdGlqdnlueWR3YjQyaWJrMDFqZyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9dHM/NEvzHap79FP0b2Of2j/giphy.gif"
      alt="Loading..." class="w-screen h-auto">
  </div>

  <script charset="utf-8" src="https://static.line-scdn.net/liff/edge/2/sdk.js"></script>

  <script>
    $(document).ready(function () {
      var liffId = "xxxxxx";
      initializeLiff(liffId);

    })

    function initializeLiff(liffId) {
      liff
        .init({
          liffId: liffId,
          withLoginOnExternalBrowser: true,
        })
        .then(() => {
          if (!liff.isInClient() && !liff.isLoggedIn()) {
            window.alert("กรุณาเข้าสู่ระบบบัญชี LINE ของคุณ");
            liff.login({ redirectUri: location.href });

          }
          liff.ready.then(() => {
            liff.getProfile()
              .then((profile) => {
                const name = profile.displayName;
                const userId = profile.userId;
                const params = (new URL(document.location)).searchParams;
                const key = params.get("key");
                document.getElementById("displayname").textContent = name
                document.getElementById("title").textContent = "สวัสดีคุณ " + name

                sendToGoogleSheet(userId, name, key)
              })
              .catch((err) => {
                console.log("error", err);
              });



          });
        })
        .catch((err) => {
          console.log('LIFF Initialization failed ', err);
        });
    }





    function sendToGoogleSheet(userId, name, key) {
      $('#loading-overlay').removeClass('hidden');
      $.post('https://script.google.com/macros/s/xxxxxx/exec', {

        userId: userId,
        name: name,
        key: key
      })
        .done(function (response) {
          $('#loading-overlay').addClass('hidden');
          var statusCode = response.statusCode;
          console.log("Status code from response:", statusCode);
          if (statusCode === 200) {
            var flexMessage = response.body;
            // sendMessages(flexMessage);
            shareMessages(flexMessage)
          } else {
            Swal.fire("ไม่ถูกต้อง", "กรุณาลองใหม่อีกครั้ง", "error")
              .then(() => liff.closeWindow());
          }
        })
        .fail(function (error) {
          console.error("Error sending to Google Sheet:", error);
          $('#loading-overlay').addClass('hidden');
          Swal.fire("ผิดพลาด", "กรุณาทำรายการใหม่อีกครั้ง", "error")
            .then(() => liff.closeWindow());
        });
    }
    function sendMessages(messages) {
      if (!liff.isInClient()) {
        Swal.fire("ผิดพลาด", "โปรดใช้เฉพาะมือถือเท่านั้น", "error")
        console.error("LIFF is not opened inside the LINE app.");
        return;
      }

      liff.sendMessages(messages)
        .then(() => {
          Swal.fire({
            title: "🎉ดำเนินการสำเร็จ🎉",
            text: "ทำการส่ง Message เรียบร้อย",
            icon: "success",
            confirmButtonText: 'ตกลง'
          }).then(() => {
            liff.closeWindow();
          });
        })
        .catch(error => {
          console.error("Failed to send message:", error);
          Swal.fire("เกิดข้อผิดพลาด!", "โปรดลองใหม่อีกครั้ง", "error")
            .then(() => liff.closeWindow());
        });
    }

    function shareMessages(messages) {


      liff.shareTargetPicker(messages).then(function (res) {
        if (res) {
          Swal.fire({
            title: "ดำเนินการสำเร็จ ✔️",
            text: "ทำการ Share Message เรียบร้อย",
            icon: "success",
            confirmButtonText: 'ตกลง'
          }).then(() => {
            liff.closeWindow();
          });
        } else {

          console.log("TargetPicker was closed!");
        }
      })
        .catch(function (error) {

          console.log("something wrong happen");
          Swal.fire("เกิดข้อผิดพลาด!", "โปรดลองใหม่อีกครั้ง", "error")
            .then(() => liff.closeWindow());
        });

    }




    const colors = ["#3CC157", "#2AA7FF", "#1B1B1B", "#FCBC0F", "#F85F36"];

    const numBalls = 50;
    const balls = [];

    for (let i = 0; i < numBalls; i++) {
      let ball = document.createElement("div");
      ball.classList.add("ball");
      ball.style.background = colors[Math.floor(Math.random() * colors.length)];
      ball.style.left = `${Math.floor(Math.random() * 100)}vw`;
      ball.style.top = `${Math.floor(Math.random() * 100)}vh`;
      ball.style.transform = `scale(${Math.random()})`;
      ball.style.width = `${Math.random()}em`;
      ball.style.height = ball.style.width;

      balls.push(ball);
      document.body.append(ball);
    }


    balls.forEach((el, i, ra) => {
      let to = {
        x: Math.random() * (i % 2 === 0 ? -11 : 11),
        y: Math.random() * 12
      };

      let anim = el.animate(
        [
          { transform: "translate(0, 0)" },
          { transform: `translate(${to.x}rem, ${to.y}rem)` }
        ],
        {
          duration: (Math.random() + 1) * 2000,
          direction: "alternate",
          fill: "both",
          iterations: Infinity,
          easing: "ease-in-out"
        }
      );
    });

  </script>
</body>

</html>
