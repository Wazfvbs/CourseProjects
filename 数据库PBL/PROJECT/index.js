const express = require('express');
const bodyParser = require('body-parser');
const oracledb = require('oracledb');

const app = express();
app.use(bodyParser.json());

// 数据库连接配置
const dbConfig = {
    user: 'ld2022211477',
    password: 'ld2022211477',
    connectString: '222.27.161.245:1521/orcl'
};

// 添加菜品的API接口
app.post('/api/merchant/dishes', async (req, res) => {
    const { name, price, description } = req.body;

    if (!name || !price) {
        return res.status(400).send('Name and price are required');
    }

    let connection;

    try {
        connection = await oracledb.getConnection(dbConfig);

        const sql = `INSERT INTO Dish (DishID, Name, Price, Description, MerchantID) VALUES (seq_dish_id.NEXTVAL, :name, :price, :description, :merchantId)`;
        const binds = {
            name: name,
            price: price,
            description: description,
            merchantId: 1 // 示例商家ID，可以从请求中获取
        };
        
        const result = await connection.execute(sql, binds, { autoCommit: true });
        res.status(201).send({ id: result.lastRowid, ...req.body });
    } catch (err) {
        console.error(err);
        res.status(500).send(err.message);
    } finally {
        if (connection) {
            try {
                await connection.close();
            } catch (err) {
                console.error(err);
            }
        }
    }
});

const PORT = process.env.PORT || 5000;
app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});
