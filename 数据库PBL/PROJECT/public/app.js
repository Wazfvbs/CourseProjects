document.getElementById('dishForm').addEventListener('submit', function(event) {
    event.preventDefault(); // 阻止表单的默认提交行为
    
    const formData = {
        name: document.getElementById('name').value,
        price: document.getElementById('price').value,
        description: document.getElementById('description').value
    };
    
    fetch('/api/merchant/dishes', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(formData)
    })
    .then(response => response.json())
    .then(data => {
        console.log('Success:', data);
        // 可以在这里添加更多逻辑，比如显示成功消息或者清空表单
    })
    .catch((error) => {
        console.error('Error:', error);
    });
});
