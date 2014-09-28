    <div>
      <table class="table table-striped">
          <thead>
            <tr>
              <th>Symbol</th>
              <th>Company</th>
              <th>Shares</th>
              <th>Price</th>
              <th>Total</th>
            </tr>
          </thead>
          <tbody>
        <?php foreach($positions as $position): ?> 
            <?php $total = number_format(($position["price"] * $position["shares"]), 2); ?>  
            <tr>
              <td style="text-align: left;"><?= $position["symbol"] ?></td>
              <td style="text-align: left;"><?= $position["name"] ?></td>
              <td style="text-align: left;"><?= $position["shares"] ?></td>
              <td style="text-align: left;"><?= "$" . $position["price"] ?></td>
              <td style="text-align: left;"><?= "$" . $total ?></td>
            </tr>    
        <?php endforeach ?>
            <tr>
              <td style="text-align: left;"><strong>Cash Balance:</strong></td>
              <td colspan="3"></td>
              <td style="text-align: left;"><strong><?= "$" . number_format($user["cash"], 2) ?></strong></td>
            </tr>
        </tbody> 
      </table>    
    </div>
