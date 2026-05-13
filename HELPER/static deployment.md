# Static Website Deployment on Cloud VM (EC2) nginx

## 📌 Objective

Design and deploy a static website on a cloud virtual machine. Configure server and networking so the website is publicly accessible and can be updated remotely.

---

## 🚀 Technologies Used

* Cloud Platform: Amazon Web Services (AWS)
* Service: EC2 (Virtual Machine)
* Web Server: Nginx
* Protocol: HTTP
* Access: SSH

---

## 📂 Project Structure

```
static-website-ec2/
│
├── website/
│   └── index.html
│
└── README.md
```

---

# ⚙️ Execution Steps (From Scratch)

## 🔹 Step 1: Launch EC2 Instance

1. Login to AWS Console
2. Open EC2 Dashboard
3. Click **Launch Instance**
4. Configure:

   * OS: Ubuntu
   * Instance Type: t2.micro
   * Key Pair: Create & download `.pem`

---

## 🔹 Step 2: Configure Security Group

Allow:

* SSH (22) → Your IP
* HTTP (80) → Anywhere (0.0.0.0/0)

---

## 🔹 Step 3: Connect to Instance

```
ssh -i "path/to/key.pem" ubuntu@your-public-ip
```

---

## 🔹 Step 4: Install Web Server

```
sudo apt update
sudo apt install nginx -y
```

Start server:

```
sudo systemctl start nginx
sudo systemctl enable nginx
```

---

## 🔹 Step 5: Deploy Website

```
cd /var/www/html
sudo rm index.nginx-debian.html
sudo nano index.html
```

Paste your HTML code and save.

---

## 🔹 Step 6: Access Website

Open in browser:

```
http://your-public-ip
```

---

## 🔹 Step 7: Remote Updates

```
ssh -i "path/to/key.pem" ubuntu@your-public-ip
cd /var/www/html
sudo nano index.html
```

---

## 📸 Output

Add screenshots:

* EC2 instance running
* Security group rules
* Website in browser

---

## ⚠️ Notes

* Ensure instance is running
* Ensure port 80 is open
* Use correct public IP (not private IP)
* Stop instance when not in use to save cost

---

## 🎓 Learning Outcomes

* Learned cloud VM deployment
* Configured web server (Nginx)
* Enabled public access using networking rules
* Managed remote updates via SSH

---

## 🚀 Future Enhancements

* Add custom domain (Route 53)
* Enable HTTPS using SSL
* Use S3 + CloudFront for scalable hosting


helper docs:-https://docs.google.com/document/d/1tsO0jQlyjhA00zW7goh0_WypLY-FuwjcfRMMoROSniw/edit?tab=t.0
# Static Website Deployment on AWS EC2 (Ubuntu) apache2

This project demonstrates how to design and deploy a static website on a cloud virtual machine using Amazon EC2. The server is configured to be publicly accessible and supports remote updates using multiple methods.

---

## Step 1: Connect to Ubuntu EC2 Instance

```bash
chmod 400 your-key.pem
ssh -i your-key.pem ubuntu@<public-ip>
```

Note: Default username for Ubuntu is `ubuntu`

---

## Step 2: Update System

```bash
sudo apt update
sudo apt upgrade -y
```

---

## Step 3: Install Apache Web Server

```bash
sudo apt install apache2 -y
```

Start and enable Apache:

```bash
sudo systemctl start apache2
sudo systemctl enable apache2
```

---

## Step 4: Test Website

Open in browser:

```
http://<your-public-ip>
```

You should see the default Apache page.

---

## Step 5: Deploy Your Static Website

Navigate to web root:

```bash
cd /var/www/html
```

Remove default file:

```bash
sudo rm index.html
```

Create a new file:

```bash
sudo nano index.html
```

Paste the following HTML:

```html
<!DOCTYPE html>
<html>
<head>
  <title>AWS Ubuntu Website</title>
</head>
<body>
  <h1>Hello from Ubuntu EC2</h1>
</body>
</html>
```

Save and exit:
- Press `Ctrl + X`
- Press `Y`
- Press `Enter`

Refresh browser to view your website.

---

## Step 6: Fix Permissions

```bash
sudo chown -R ubuntu:ubuntu /var/www/html
```

---

## Step 7: Configure Security Group

In AWS console, ensure:

- HTTP (Port 80) → 0.0.0.0/0  
- SSH (Port 22) → Your IP  

---

## Step 8: Remote Update Methods

### Method 1: SSH (Direct Editing)

```bash
nano /var/www/html/index.html
```

- Edit files directly on the server
- Changes reflect instantly on the live website

---

### Method 2: SCP (File Transfer)

From your local machine:

```bash
scp -i your-key.pem index.html ubuntu@<public-ip>:/home/ubuntu
```

Move file to web directory:

```bash
mv index.html /var/www/html/
```

---

### Method 3: Git Deployment

Install Git:

```bash
sudo apt install git -y
```

Clone your repository:

```bash
cd /var/www/html
git clone https://github.com/<your-username>/<repo-name>.git .
```

For updates:

```bash
git pull
```

---

## Conclusion

A static website is successfully deployed on an Ubuntu EC2 instance. The server is publicly accessible and can be updated remotely using SSH, SCP, or Git.