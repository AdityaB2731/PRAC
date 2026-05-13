import nltk
from nltk.chat.util import Chat, reflections

pairs = [
    [r"hi|hello|hey", ["Hello!", "Hi there!"]],
    
    [r"(.*) price (.*)",
     ["Our products start from ₹999."]],

    [r"(.*) refund (.*)",
     ["Refund is available within 7 days."]],

    [r"(.*) delivery (.*)",
     ["Delivery takes 3-5 business days."]],

    [r"(.*) your name ?",
     ["I am a chatbot created for customer support."]],

    [r"bye",
     ["Goodbye! Have a nice day."]],

    [r"(.*)",
     ["Sorry, I didn't understand that."]]
]

def start_chat():

    chatbot = Chat(pairs, reflections)

    print("Chatbot Started\n")

    while True:

        user = input("User: ")

        if user.lower() == "bye":
            print("Chatbot: Goodbye! Have a nice day.")
            break

        response = chatbot.respond(user)

        print("Chatbot:", response)

start_chat()
# this is rule based chatbot





# <!DOCTYPE html>
# <html>
# <head>
#     <title>Simple Chatbot</title>
# </head>

# <body>

# <h2>Customer Support Chatbot</h2>

# <div id="chat"></div>

# <br>

# <input type="text" id="msg" placeholder="Type message">
# <button onclick="reply()">Send</button>

# <script>

# function getBotResponse(input) {

#     input = input.toLowerCase();

#     if(input.includes("hello") || input.includes("hi"))
#         return "Hello! How can I help you?";

#     else if(input.includes("price"))
#         return "Our products start from ₹999.";

#     else if(input.includes("refund"))
#         return "Refund available within 7 days.";

#     else if(input.includes("delivery"))
#         return "Delivery takes 3-5 days.";

#     else if(input.includes("bye"))
#         return "Goodbye!";

#     else
#         return "Sorry, I didn't understand.";
# }

# function reply() {

#     let msg = document.getElementById("msg").value;

#     if(msg == "")
#         return;

#     let response = getBotResponse(msg);

#     let chat = document.getElementById("chat");

#     chat.innerHTML += "<p><b>User:</b> " + msg + "</p>";

#     chat.innerHTML += "<p><b>Chatbot:</b> " + response + "</p>";

#     document.getElementById("msg").value = "";
# }

# </script>

# </body>
# </html>
# this is gui based chatbot using html and javascript