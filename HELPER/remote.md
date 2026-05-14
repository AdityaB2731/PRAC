# 🌐 Secure Communication Between Two EC2 Instances in AWS

## 📌 Problem Statement
Create a cloud-based environment where two virtual machines communicate securely within a virtual network. Implement file transfer between instances while ensuring proper access permissions.

---

## 🏗️ Architecture Overview
- Custom VPC
- One Subnet
- Internet Gateway
- Route Table
- 2 EC2 Instances (VM1 & VM2)
- SSH-based secure communication
- File transfer using SCP
- File permission control

---

## ⚙️ Step-by-Step Implementation

### 1. Create VPC
- Go to AWS Console → VPC → Create VPC  
- Name: `MyVPC`  
- CIDR: `10.0.0.0/16`

---

### 2. Create Subnet
- Name: `MySubnet`  
- CIDR: `10.0.1.0/24`  
- Attach to `MyVPC`

---

### 3. Create & Attach Internet Gateway
- Create IGW (`MyIGW`)  
- Attach it to `MyVPC`

---

### 4. Create Route Table
- Name: `MyRouteTable`
- Add route:

0.0.0.0/0 → Internet Gateway

- Associate with `MySubnet`

---

### 5. Launch EC2 Instances
Create:
- `VM1`
- `VM2`

Configuration:
- AMI: Ubuntu
- Instance Type: t2.micro
- VPC: `MyVPC`
- Subnet: `MySubnet`
- Enable Public IP
- Key Pair: `.pem`

---

### 6. Configure Security Group
Allow:
- SSH (22) → My IP  
- SSH (22) → Same Security Group  
- ICMP (All) → Same Security Group  

---

### 7. Connect to VM1
```bash
ssh -i your-key.pem ubuntu@<VM1-public-IP>
```
### 8. Test Connectivity
```
ping <VM2-private-IP>
```

### 9. Generate SSH Key (VM1)
```
ssh-keygen
```

### 10. Copy Public Key
```
cat ~/.ssh/id_ed25519.pub
```

### 11. Paste Key in VM2
```
nano ~/.ssh/authorized_keys
```

### 12. Set Permissions (VM2)
```
chmod 700 ~/.ssh
chmod 600 ~/.ssh/authorized_keys
```

### 13. Test SSH Connection
```
ssh ubuntu@<VM2-private-IP>
```

### 14. Create File (VM1)
```
echo "Hello from VM1" > file.txt
```

### 15. Transfer File
```
scp file.txt ubuntu@<VM2-private-IP>:/home/ubuntu/
```

### 16. Verify File (VM2)
```
ls
cat file.txt
```


## 🔐 Security Measures
Private IP communication inside VPC
SSH key-based authentication
Restricted access via Security Groups
File-level permission control

##  Errors Faced & Solutions
1. Internet Gateway Detached

Issue: No internet access
Fix: Attach IGW to VPC + update route table

2. Subnet Not Associated

Issue: Routes not applied
Fix: Associate subnet with custom route table

3. Ping Not Working

Issue: ICMP blocked
Fix: Allow ICMP in Security Group

4. SSH Key Not Found
cat ~/.ssh/id_rsa.pub

Error: File not found
Fix: ssh-keygen

5. Permission Denied (publickey)

Cause:

Wrong key (id_rsa vs id_ed25519)
Key not pasted properly

Fix:

cat ~/.ssh/id_ed25519.pub

Paste into:

nano ~/.ssh/authorized_keys

Then:

chmod 700 ~/.ssh
chmod 600 ~/.ssh/authorized_keys

## 🧠 Conclusion
Successfully created a secure AWS environment where:

Two EC2 instances communicate using private IP
Secure SSH authentication is implemented
Files are transferred with proper permissions